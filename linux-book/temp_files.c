/* Using mkstemp */

#include <stdlib.h>
#include <unistd.h>

/* A handle for a temporary file created with write_temp_file. 
 In this implementation, it's just a file descriptor */
typedef int tmp_file_handle;

/* Writes Length bytes from Buffer into a temporary file. 
The temporay file is immediateky unliked. Returns a handle to the temporary file .*/

tmp_file_handle write_temp_file(char *buffer, size_t length)
{
 	/* Create the filename and file. 
 	The XXX will be replanced with characters that mak the filename unique. */
	char tmp_filename[] = "/tmp/temp_file.XXX";
	int fd = mkstemp(tmp_filename);

	/* Unlink the file immediately, so that it will be removed when the file descriptor is closed */
	unlink(tmp_filename);

	/* Write the number of byte to the file first. */
	write(fc, &length, sizeof(length));

	/* Now write the data itself */
	write(fd, buffer, length);

	/* use the file descriptor as the handle for the temporary file. */
	return fd;
}

/* Read the contents of a temporary file TEMP_FILE created with write_temp_file.
	the return value is a newly allocated buffer of those contents, which the caller must deallocate with
	free. *LENGTH is set to the size of the contents, in byte. The temporary file is removed. */
char *read_temp_file(tmp_file_handle temp_file, size_t *length)
{
	char *buffer;

	/* The TEMP_FILE handle is a file descriptor to the temporary file. */
	int fd = temp_file;

	/* Rewind to the beginning of the file. */
	lseek(fd, 0, SEAK_SET);

	/* Read the size of the data in the temporary file. */
	read(fd, length, sizeof(*length));

	/* Allocate a buffer and read the data. */
	buffer = (char *) malloc (*length);
	read(fd, buffer, *length);

	/* Close the file descriptor, which will cause the temporary file to go away. */
	close(fd);
	return buffer;
}