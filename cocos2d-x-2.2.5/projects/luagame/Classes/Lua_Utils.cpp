/*
** Lua binding: luagame
** Generated automatically by tolua++-1.0.92 on Fri Aug 22 11:04:22 2014.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luagame_open (lua_State* tolua_S);

#include "cocos2d.h"
#include "cocos-ext.h"
#include "TestClass.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"TestClass");
}

/* method: TestLog of class  TestClass */
#ifndef TOLUA_DISABLE_tolua_luagame_TestClass_TestLog00
static int tolua_luagame_TestClass_TestLog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestClass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestClass::TestLog();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TestLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_luagame_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"TestClass","TestClass","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TestClass");
   tolua_function(tolua_S,"TestLog",tolua_luagame_TestClass_TestLog00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luagame (lua_State* tolua_S) {
 return tolua_luagame_open(tolua_S);
};
#endif

