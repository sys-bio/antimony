using Antimony
using Test

const ant_str = """
model test_model
    J0: S1 -> S2; k1*S1
    S1 = 10; S2 = 0; k1 = 0.5
end
"""

@testset "version" begin
    @test occursin(r"\d+\.\d+", Antimony.getVersionStr())
end

@testset "load and query modules" begin
    @test Antimony.loadAntimonyString(ant_str) isa Integer
    @test Antimony.getNumModules() >= 1
    @test "test_model" in Antimony.getModuleNames()
    @test Antimony.getMainModuleName() in Antimony.getModuleNames()
    @test Antimony.getNthModuleName(0) in Antimony.getModuleNames()
    @test Antimony.checkModule("test_model")
    @test !Antimony.checkModule("no_such_module")
end

@testset "output" begin
    sbml = Antimony.getSBMLString("test_model")
    @test occursin("<sbml", sbml)
    @test occursin("S1", sbml)

    ant = Antimony.getAntimonyString("test_model")
    @test occursin("S1", ant)

    mktempdir() do dir
        path = joinpath(dir, "test_model.xml")
        @test Antimony.writeSBMLFile(path, "test_model") != 0
        @test isfile(path)
        @test occursin("<sbml", read(path, String))
    end
end

@testset "round trip through SBML" begin
    sbml = Antimony.getSBMLString("test_model")
    Antimony.loadSBMLString(sbml)
    @test Antimony.getNumModules() >= 1
    @test occursin("S1", Antimony.getAntimonyString(Antimony.getMainModuleName()))
end

@testset "file round trips" begin
    Antimony.loadAntimonyString(ant_str)
    mktempdir() do dir
        ant_path = joinpath(dir, "test_model.ant")
        sbml_path = joinpath(dir, "test_model.xml")
        comp_path = joinpath(dir, "test_model_comp.xml")

        @test Antimony.writeAntimonyFile(ant_path, "test_model") != 0
        @test occursin("S1", read(ant_path, String))
        @test Antimony.writeSBMLFile(sbml_path, "test_model") != 0
        @test occursin("<sbml", read(sbml_path, String))
        @test Antimony.writeCompSBMLFile(comp_path, "test_model") != 0
        @test occursin("<sbml", read(comp_path, String))

        loads = (
            (Antimony.loadAntimonyFile, ant_path),
            (Antimony.loadSBMLFile, sbml_path),
            (Antimony.loadSBMLFile, comp_path),
            (Antimony.loadFile, ant_path),
            (Antimony.loadFile, sbml_path),
        )
        for (loader, path) in loads
            Antimony.clearPreviousLoads()
            @test loader(path) isa Integer
            @test Antimony.getNumModules() >= 1
            @test occursin("S1", Antimony.getAntimonyString(Antimony.getMainModuleName()))
        end
    end
end

@testset "errors" begin
    bad_str = """
        A -> B; k1*A,
        A = 10,
    """
    @test_throws ErrorException Antimony.loadAntimonyString(bad_str)
    @test !isempty(Antimony.getLastAntimonyError())
    @test_throws ErrorException Antimony.getSBMLString("no_such_module")
    @test_throws ErrorException Antimony.loadFile("this_file_does_not_exist.txt")
end

@testset "warnings are strings" begin
    @test Antimony.getWarnings() isa String
end

Antimony.clearPreviousLoads()
Antimony.freeAll()
