GITURL = https://github.com/mysqludf/lib_mysqludf_skeleton.git
lib_LTLIBRARIES = lib_mysqludf_skeleton.la
lib_mysqludf_skeleton_la_SOURCES = lib_mysqludf_skeleton.cc mysqludf.cc
lib_mysqludf_skeleton_la_CXXFLAGS = -DSTANDARD -DMYSQL_SERVER @MYSQL_CFLAGS@
lib_mysqludf_skeleton_la_LDFLAGS = -module -avoid-version -no-undefined -rpath @MYSQL_PLUGINDIR@

EXTRA_DIST = *.h test *.sql API

.PHONY : test

mrproper:
	make clean
	make test-clean
	make maintainer-clean
	rm -rf config.guess config.h.* config.status configure config.sub ltmain.sh depcomp aclocal.m4 install.sh config.log compile missing Makefile.in doc/html *.lo mkinstalldirs install-sh *~ config/ltmain.sh config/libtool.m4 config/ltoptions.m4 config/ltversion.m4 config/lt~obsolete.m4
 
installdb: 
	$(MYSQL) < ./installdb.sql

uninstalldb: 
	$(MYSQL) < ./uninstalldb.sql=
	
dist-hook:
	find $(distdir) -name .svn -o -name .DS_Store -o -name .cdtproject -o -name .project -o -name .settings -o *~ | xargs --no-run-if-empty rm -rf

test:
	for i in `ls test/*.result | awk -F "." '{print $$1}'`; do echo "$$i"; $(MYSQLTEST) --result-file=$$i.result < $$i.test; done

test-results:
	for i in `ls test/*.test | awk -F "." '{print $$1}'`; do echo "$$i"; $(MYSQLTEST) --result-file=$$i.result --record < $$i.test; done

test-clean:
	rm -f test/*.log test/*.reject

gh-pages:
	[ -e gh-pages ] || git clone -b gh-pages $(GITURL) gh-pages
	git clone https://github.com/mysqludf/mysqludf.github.com _tmp
	cp _tmp/_layouts/* gh-pages/_layouts
	cp _tmp/_inlcudes/* gh-pages/_includes
	rm -rf _tmp

