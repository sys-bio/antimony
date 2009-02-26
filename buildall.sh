for i in *.pro ;do  qmake $i -o QMakeFile && make -f QMakeFile; done
