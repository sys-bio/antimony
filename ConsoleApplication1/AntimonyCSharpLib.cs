using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Antimony
{
    public class AntimonyInterface
    {

        const string ANTIMONY_LIB = "Antimonyd";

        private static string getStringFromPtr(IntPtr pointer)
        {
            string sResult = Marshal.PtrToStringAnsi(pointer);
            return sResult;
        }

        private static string[] getStringArrayFromPtr(IntPtr pointer, int nLength)
        {
            IntPtr[] rawRows = new IntPtr[nLength];
            string[] oResult = new string[nLength];
            Marshal.Copy(pointer, rawRows, 0, nLength);
            for (int i = 0; i < nLength; i++)
            {
                oResult[i] = Marshal.PtrToStringAnsi(rawRows[i]);

            }
            return oResult;
        }

        [DllImport(ANTIMONY_LIB, EntryPoint = "checkModuleName", ExactSpelling = false,
            CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int checkModuleName(string name);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNumModuleNames", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int getNumModuleNames();

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNthModuleName", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern string getNthModuleName(int n);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getModuleNames", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetModuleNames();

        [DllImport(ANTIMONY_LIB, EntryPoint = "loadModel", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int loadModel(string fileName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getJarnac", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetJarnac(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNumFloatingSpecies", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int getNumFloatingSpecies(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNthFloatingSpeciesName", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetNthFloatingSpeciesName(string moduleName, int n);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNumBoundarySpecies", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int getNumBoundarySpecies(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNthBoundarySpeciesName", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetNthBoundarySpeciesName(string moduleName, int n);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getFloatingSpeciesList", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetFloatingSpeciesList(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getBoundarySpeciesList", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetBoundarySpeciesList(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getReactionNameList", ExactSpelling = false,
         CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetReactionNameList(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNthKineticLaw", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetNthKineticLaw(string moduleName, int n);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNumReactions", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int getNumReactions(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNumberReactants", ExactSpelling = false,
             CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int getNumReactants(string moduleName, int n);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getNumberProducts", ExactSpelling = false,
            CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern int getNumProducts(string moduleName, int n);

        [DllImport(ANTIMONY_LIB, EntryPoint = "getStoichiometryMatrix", ExactSpelling = false,
            CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr internalGetStoichiometryMatrix(string moduleName);

        [DllImport(ANTIMONY_LIB, EntryPoint = "freeMatrix", ExactSpelling = false,
            CharSet = CharSet.Ansi, SetLastError = true)]
        public static extern IntPtr freeMatrix(IntPtr pointer, int nRows);


        public static string[] getModuleNames()
        {
            IntPtr pointer = internalGetModuleNames();
            int nItems = getNumModuleNames();

            return getStringArrayFromPtr(pointer, nItems);
        }

        public static string getJarnac(string moduleName)
        {
            IntPtr pointer = internalGetJarnac(moduleName);
            return getStringFromPtr(pointer);
        }

        public static string getNthFloatingSpeciesName(string moduleName, int n)
        {
            IntPtr pointer = internalGetNthFloatingSpeciesName(moduleName, n);
            return getStringFromPtr(pointer);
        }

        public static string getNthBoundarySpeciesName(string moduleName, int n)
        {
            IntPtr pointer = internalGetNthBoundarySpeciesName(moduleName, n);
            return getStringFromPtr(pointer);
        }

        public static string[] getFloatingSpeciesList(string moduleName)
        {
            IntPtr pointer = internalGetFloatingSpeciesList(moduleName);
            int nItems = getNumFloatingSpecies(moduleName);
            IntPtr[] ptrList = new IntPtr[nItems];
            string[] nameList = new string[nItems];
            Marshal.Copy(pointer, ptrList, 0, nItems);
            for (int i = 0; i < nItems; i++)
                nameList[i] = Marshal.PtrToStringAnsi(ptrList[i]);
            return nameList;
        }

        public static string[] getBoundarySpeciesList(string moduleName)
        {
            IntPtr pointer = internalGetBoundarySpeciesList(moduleName);
            int nItems = getNumBoundarySpecies(moduleName);
            IntPtr[] ptrList = new IntPtr[nItems];
            string[] nameList = new string[nItems];
            Marshal.Copy(pointer, ptrList, 0, nItems);
            for (int i = 0; i < nItems; i++)
                nameList[i] = Marshal.PtrToStringAnsi(ptrList[i]);
            return nameList;
        }

        public static string[] getReactionNameList(string moduleName)
        {
            IntPtr pointer = internalGetReactionNameList(moduleName);
            int nItems = getNumReactions(moduleName);

            return getStringArrayFromPtr(pointer, nItems);
        }

        public static string getNthKineticLaw(string moduleName, int n)
        {
            IntPtr pointer = internalGetNthKineticLaw(moduleName, n);
            return getStringFromPtr(pointer);
        }

        public static double[][] getStoichiometryMatrix(string moduleName)
        {
            IntPtr pointer = internalGetStoichiometryMatrix(moduleName);
            int nRows = getNumFloatingSpecies(moduleName);
            int nCols = getNumReactions(moduleName);

            IntPtr[] rawRows = new IntPtr[nRows];
            double[][] oResult = new double[nRows][];
            Marshal.Copy(pointer, rawRows, 0, nRows);
            for (int i = 0; i < nRows; i++)
            {
                oResult[i] = new double[nCols];
                Marshal.Copy(rawRows[i], oResult[i], 0, nCols);
            }
            freeMatrix(pointer, nRows);
            return oResult;
        }
    }
}
