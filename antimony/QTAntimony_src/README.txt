QTAntimony is a GUI text editor for Antimony models and files.  Its use 
should be fairly straightforward--new models can either be typed in from 
scratch, or files can be opened.  Antimony models are translated to SBML 
models, which can be viewed and edited in the other displayed tabs.

Once you start editing a particular tab, that tab is considered to be 
the 'canonical' version of the model you are editing.  When you switch 
to a tab of the other format, your canonical version will be translated 
(using libAntimony) and displayed.  Canonical versions are denoted 
visually by the addition of a black border around the text.  You can 
also translate a model by hitting Control-T, or by selecting the 
'Translate' option from the edit menu.

Since Antimony files may contain multiple models, each model is given a 
separate SBML tab once the Antimony model is translated.  Each SBML tab 
may be saved separately as its own file (a 'flattened' version of the 
file will be produced in the case of Antimony models with sub-models).  
If you edit an SBML tab when there are multiple models, it will be 
translated to Antimony when you return to the Antimony tab, but only 
that one model will be translated--the others should remain as they 
were.

If the current tab's model(s) can not be translated due to an error, the 
error is displayed, and no translation occurs.  This puts the program in 
an unsynchronized state, where the contents of the SBML tab(s) are not 
the same as the contents of the Antimony tab.  Whichever tab you edit 
after that will become the new canonical model for the system.

The current version is v0.6, and you should expect there to be some 
bugs, particularly when there are errors in the models.  We are actively 
updating this program as well as libAntimony, however, and would 
appreciate any bug reports or feature requests you may have.  You can 
either email us directly at lpsmith@u.washington.edu, or use the bug 
tracking feature of sourceforget at 

http://sourceforge.net/tracker/?group_id=251883&atid=1126927

Thank you for using Antimony!
