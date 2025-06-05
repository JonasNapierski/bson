#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

// https://bsonspec.org/spec.html
#define BSON_TYPE_DOUBLE 1
#define BSON_TYPE_STRING 2
#define BSON_TYPE_EMBEDDED_DOCUMENT 3
#define BSON_TYPE_ARRAY 4
#define BSON_TYPE_BINARY 5
#define BSON_TYPE_UNDEFINED 6
#define BSON_TYPE_OBJECT_ID 7

// 0x15 0x00 0x00 0x00
// 0x02
// 0x6e 0x61 0x6d 0x65 0x00
// 0x06 0x00 0x00 0x00 0x68 0x65 0x6c 0x6c 0x6f 0x00
// 0x00
// 0x0f 0x00 0x00 0x00
// 0x10
// 0x6e 0x61 0x6d 0x65 0x00 0x63 0x00 0x00 0x00
// 0x00


// 0x20 0x00 0x00 0x00
// <--- Doc Size ---->
// 0x02 <- type  "string" 
// 0x6e 0x61 0x6d 0x65 0x00 <- e_name
//    n    a    m    e   \0
// 0x06 0x00 0x00 0x00 0x68 0x65 0x6c 0x6c 0x6f 0x00
//   size -----------|    h    a    l    l   o    \0
// 0x10 <- type "int32"
// 0x76 0x61 0x6c 0x75 0x65 0x00
//    v    a    l    u    e   \0
// 0x03 0x00 0x00 0x00
//    3
// 0x00

struct bson_element {
    uint8_t type;  
    void *value;
    // *value could be just int32 or (int32 + str * size)
};

struct bson_document {
    uint32_t size; // in bytes
    struct bson_element *elements;
};

bool bson_validate_bracket(const char *json, int json_length)
{
    int brackets = 0;
    for( int i = 0; i < json_length; i++)
    {
        if (json[i] == '{') brackets++;
        if (json[i] == '}') brackets--;
    }

    return brackets != 0;
}

void bson_create(const char *json)
{
    int json_length = strlen(json);

    if (bson_validate_bracket(json, json_length))
    {
        printf("Fail to valid json structure");
        return;
    }


    printf(json);
}

int main(void) {
    printf("Hello World\n");
    bson_create("{\"hello\": \"world\"}");

    return 0;
}
