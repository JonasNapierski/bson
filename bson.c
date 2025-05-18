#include <stdio.h>

// https://bsonspec.org/spec.html
#define BSON_TYPE_DOUBLE 1
#define BSON_TYPE_STRING 2
#define BSON_TYPE_EMBEDDED_DOCUMENT 3
#define BSON_TYPE_ARRAY 4
#define BSON_TYPE_BINARY 5
#define BSON_TYPE_UNDEFINED 6
#define BSON_TYPE_OBJECT_ID 7



void bson_create(const char *json)
{
    printf(json);
}

int main(void) {
    printf("Hello World\n");
    bson_create("{\"hello\": \"world\"}");

    return 0;
}
