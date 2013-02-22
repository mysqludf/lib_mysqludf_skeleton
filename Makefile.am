lib_LTLIBRARIES = lib_mysqludf_skeleton.la
lib_mysqludf_skeleton_la_SOURCES = lib_mysqludf_skeleton.c mysqludf.c
lib_mysqludf_skeleton_la_CFLAGS = -DSTANDARD -DMYSQL_SERVER @MYSQL_CFLAGS@
lib_mysqludf_skeleton_la_CXXFLAGS = -DSTANDARD -DMYSQL_SERVER @MYSQL_CFLAGS@
lib_mysqludf_skeleton_la_LDFLAGS = -module -avoid-version -no-undefined -rpath @MYSQL_PLUGINDIR@

EXTRA_DIST = *.h *.sql
SUBDIRS = test

mrproper:
	make clean
	make maintainer-clean
	rm -rf config.guess config.h.* config.status configure config.sub ltmain.sh depcomp aclocal.m4 install.sh config.log compile missing Makefile.in doc/html *.lo mkinstalldirs install-sh *~ config/ltmain.sh config/libtool.m4 config/ltoptions.m4 config/ltversion.m4 config/lt~obsolete.m4
 
installdb: 
	$(MYSQL) < ./installdb.sql

uninstalldb: 
	$(MYSQL) < ./uninstalldb.sql
	
dist-hook:
	find $(distdir) -name .svn -o -name .git* -o -name .c9* -o -name .DS_Store -o -name .cdtproject -o -name .project -o -name .settings -o *~ | xargs --no-run-if-empty rm -rf

maintainer-dist:
	make dist
	git tag "$(VERSION)"

maintainer-diff:
	git diff "$(DIFFVERSION)" . | gitx

.PHONY : mrproper
