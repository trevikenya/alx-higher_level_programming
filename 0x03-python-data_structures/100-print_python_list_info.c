#include <stdlib.h>
#include <stdio.h>
#include <Python.h>
/**
 * print_python_list_info -  function that prints some basic
 *info about Python lists
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
    int size = PyList_Size(p);
    int allocated = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %d\n", size);
    printf("[*] Allocated = %d\n", allocated);

    for (int i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(p, i);
        const char *type = Py_TYPE(item)->tp_name;

        printf("Element %d: %s\n", i, type);
    }
}
