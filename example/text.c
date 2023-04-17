#include "include/file_preprocessing.h"

path_wrapper * init_path_wrapper(char * path_file) {
  path_wrapper * the_pw = calloc(1, sizeof(struct PATH_WRAPPER_T));
  int path_size = end_path_pos(path_file);
  int total_path_file_size = strnlen(path_file, MAX_PATH_SIZE);
  if(path_size == 0) {
    the_pw->path = NULL;
    the_pw->filename = calloc(total_path_file_size + 1, sizeof(char));
    strncpy(the_pw->filename, path_file, total_path_file_size);
  } else {
    the_pw->path = calloc(path_size + 1, sizeof(char));
    strncpy(the_pw->path, path_file, path_size);
    the_pw->filename = calloc((total_path_file_size - path_size) + 1,
        sizeof(char));
    strncpy(the_pw->filename, path_file + path_size,
        (total_path_file_size - path_size));
  }
  if(!contains_py_extension(the_pw->filename))
    the_pw->filename = add_py_extension(the_pw->filename);
  the_pw = make_path_file(the_pw);
  return the_pw;
}

int contains_py_extension(char * filename) {
  int filename_size = strnlen(filename, MAX_PATH_SIZE);
  if(!strncmp(filename + (filename_size - PY_EXTENSION_SIZE), PY_EXTENSION,
        MAX_PATH_SIZE))
    return 1;
  else
    return 0;
}

int end_path_pos(char * path_file) {
  if(!strrchr(path_file, PATH_DELIMITER))
    return 0;
  else
    return ((int)(strrchr(path_file, PATH_DELIMITER) - path_file) + 1);
}

char * add_py_extension(char * filename) {
  int filename_size = strnlen(filename, MAX_PATH_SIZE);
  filename = realloc(filename, (filename_size + PY_EXTENSION_SIZE + 1)
      * sizeof(char));
  strncat(filename, PY_EXTENSION, PY_EXTENSION_SIZE);
  return filename;
}
