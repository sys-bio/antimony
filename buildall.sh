for i in *.pro ;do  qmake -spec macx-g++ testantimony.pro && make clean && make; done
