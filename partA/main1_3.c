
#include <stdio.h>
#include <dlfcn.h>
#include "hello_Ariel.h"
#include <stdlib.h>

int main(){
 	void (*fn)(); //func pointer
	void *lib_handle;
	char *error;
	lib_handle = dlopen("./libhelloAriel.so", RTLD_LAZY);
	if (!lib_handle) {
     		fprintf(stderr, "%s\n", dlerror());
      		exit(1);
   	}
	
	fn = dlsym(lib_handle, "printHello");

   	if ((error = dlerror()) != NULL) {

      		fprintf(stderr, "%s\n", error);
      		exit(1);
   	}
	
	fn(); // activate the func
	dlclose(lib_handle);

	return 0;
}




