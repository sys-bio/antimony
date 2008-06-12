using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

using Antimony;

namespace ConsoleApplication1
{
    class Program
    {
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

                    Console.WriteLine(String.Format("{2}{2}File: '{0}' has {1} module(s).{2}",
                         new System.IO.FileInfo(file).Name,
                         AntimonyInterface.getNumModuleNames(), 
                         Environment.NewLine));

                    string[] modules = AntimonyInterface.getModuleNames();
                    
                    foreach (string s in modules)
                    {
                        Console.WriteLine(String.Format("Module: {0} (NumSpecies: {1} NumReactions: {2} )",
                            s, AntimonyInterface.getNumFloatingSpecies(s),
                            AntimonyInterface.getNumReactions(s)));
                    }

                    Console.WriteLine();

                }
                
                
            }

            Console.Out.WriteLine("all is well");
            Console.ReadKey();
        }
    }
}
