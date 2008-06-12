using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

using Antimony;

namespace ConsoleApplication1
{
    class Program
    {
        const string ANTIMONY_LIB = "C:\\Documents and Settings\\lpsmith\\Desktop\\antimony\\bin\\Antimonyd.dll";
        [DllImport(ANTIMONY_LIB, EntryPoint = "loadModel")]
        public static extern int LoadModel(string filename);

        //[DllImport(ANTIMONY_LIB, EntryPoint = "loadModel")]
        //public static extern int LoadModel(string filename);

        static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.WriteLine("Need filename");
                Environment.Exit(-1);
            }

            for (int i = 0; i < 3; i++)
            {
                //LoadModel(args[0]);
                foreach (string file in args)
                {
                    AntimonyInterface.loadModel(file);
                    Console.WriteLine("Loading: " + new System.IO.FileInfo(file).Name);

                    Console.WriteLine(String.Format("NumModules: {0}{1}",
                         AntimonyInterface.getNumModuleNames(), Environment.NewLine));
                    string[] modules = AntimonyInterface.getModuleNames();
                    foreach (string s in modules)
                    {


                        Console.WriteLine(String.Format("{3}{1}NumSpecies: {0}{1}NumReactions: {2}{1}",
                            AntimonyInterface.getNumFloatingSpecies(s), Environment.NewLine,
                            AntimonyInterface.getNumReactions(s), s));
                    }

                }
                
                
            }

            Console.Out.WriteLine("all is well");
        }
    }
}
