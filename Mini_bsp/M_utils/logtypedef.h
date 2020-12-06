#ifndef _LOGTYPEDEF_H_
#define _LOGTYPEDEF_H_
#include <stdio.h>
 
#define DEBUG_OUTPUT    3
#define INFO_OUTPUT     2
#define WARNING_OUTPUT  1
#define ERROR_OUTPUT    0
#define DEBUG_LEVEL     2       
 
//需在使用以下打印宏的.c文件中定义“DEBUG_LEVEL”变量
#define DEBUG(info,...) \
do{ \
        if(DEBUG_LEVEL>=DEBUG_OUTPUT){\
                printf("[Debug] %s,%d:"info"",__FUNCTION__,__LINE__,##__VA_ARGS__);}\
}while(0)
 
#define INFO(info,...) \
do{ \
        if(DEBUG_LEVEL>=INFO_OUTPUT){\
                printf("[Info] %s,%d:"info"",__FUNCTION__,__LINE__,##__VA_ARGS__);}\
}while(0)
 
#define WARNING(info,...) \
do{ \
        if(DEBUG_LEVEL>=WARNING_OUTPUT){\
                printf("[Warning] %s,%d:"info"",__FUNCTION__,__LINE__,##__VA_ARGS__);}\
}while(0)
 
#define ERROR(info,...) \
do{ \
        if(DEBUG_LEVEL>=ERROR_OUTPUT){\
                printf("[Error] %s,%s,%d:"info"",(uint8_t *)__FILE__,__FUNCTION__,__LINE__,##__VA_ARGS__);}\
}while(0)
 
#endif
