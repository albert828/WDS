NAZWA_APLIKACJI=manip1
URUCHOMIENIE_APLIKACJI=${KATALOG_ROBOCZY}/${NAZWA_APLIKACJI}
ZRODLA_PROJEKTU=`/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hh\
                `/bin/pwd`/ui/*.ui
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ}\
             INCLUDEPATH+=./inc\
             INCLUDEPATH+=/usr/opt/include\
             MOC_DIR=${KATALOG_MOC}\
             UI_DIR=${KATALOG_ROBOCZY}/out/ui\
             QT+=widgets\
             QT+=opengl QT+=xml\ QT+=serialport
             LIBS+=-L/usr/opt/lib LIBS+=-lQGLViewer-qt5 LIBS+=-lSOIL\
             QMAKE_CXXFLAGS+=-std=c++11\
             TARGET=${KATALOG_ROBOCZY}/${NAZWA_APLIKACJI}


KATALOG_ROBOCZY=/tmp/opengl/05-manip1
#KATALOG_ROBOCZY=./
KATALOG_OBJ=${KATALOG_ROBOCZY}/out/obj
KATALOG_MOC=${KATALOG_ROBOCZY}/out/moc
KATALOG_PRO=${KATALOG_ROBOCZY}/out/pro

#__start__: __sprawdz_Qt__ ${KATALOG_ROBOCZY}/${NAZWA_APLIKACJI}
	#rm -f core*; ${URUCHOMIENIE_APLIKACJI}


${KATALOG_ROBOCZY}/${NAZWA_APLIKACJI}: Makefile.app __sprawdz__

__sprawdz__:
	make -f Makefile.app

Makefile.app: ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro: Makefile
	rm -fr ${KATALOG_PRO}/
	qmake -project -nopwd -o ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} -after TARGET=${KATALOG_ROBOCZY}/${NAZWA_APLIKACJI}

project: __usun_pro__ ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

#__usun_pro__:
#	rm -f ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

__clean_auxiliary_files__:
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

cleantotally: __clean_auxiliary_files__ cleanall
	rm -f  Makefile.app
	rm -rf ${KATALOG_ROBOCZY}/out

help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
