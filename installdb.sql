USE mysql;

DROP FUNCTION IF EXISTS lib_mysqludf_skeleton_info;
CREATE FUNCTION lib_mysqludf_skeleton_info RETURNS STRING SONAME 'lib_mysqludf_skeleton.so';
