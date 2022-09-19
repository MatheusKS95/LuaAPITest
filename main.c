/*
Copyright (c) 2022 Matheus Klein Schaefer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <stdio.h>

#ifdef BUILDSTATIC
#include "raylib.h"
#else
#include <raylib.h>
#endif

#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>

lua_State* L;

int main()
{
	int largura = 800;
	int altura = 600;

#ifdef DEBUG
	printf("Hello World (DEBUG)!\n");
#else
	printf("Hello World (RELEASE)!\n");
#endif
	
#ifdef BUILDSTATIC
	printf("Modo static\n");
#endif

	InitWindow(largura, altura, "Mova a bola");
	Vector2 posicao = {largura / 2, altura / 2};
	
	L = luaL_newstate();
	luaL_openlibs(L);

	while(!WindowShouldClose())
	{
		if(IsKeyDown(KEY_RIGHT))
		{
			lua_pcall(L, 0, 0, 0);
			lua_getglobal(L, "newpos");
			lua_pushnumber(L, posicao.x);
			lua_pushnumber(L, posicao.y);
			lua_pushstring(L, "right");
			
			luaL_dofile(L, "testlua.lua");
		
			lua_pcall(L, 3, 2, 0);
		
			posicao.x = (int)lua_tonumber(L, -2);
			posicao.y = (int)lua_tonumber(L, -1);
		
			lua_pop(L, 1);
		}
		if(IsKeyDown(KEY_LEFT))
		{
			lua_pcall(L, 0, 0, 0);
			lua_getglobal(L, "newpos");
			lua_pushnumber(L, posicao.x);
			lua_pushnumber(L, posicao.y);
			lua_pushstring(L, "left");
			
			luaL_dofile(L, "testlua.lua");
		
			lua_pcall(L, 3, 2, 0);
		
			posicao.x = (int)lua_tonumber(L, -2);
			posicao.y = (int)lua_tonumber(L, -1);
		
			lua_pop(L, 1);
		}
		if(IsKeyDown(KEY_UP))
		{
			lua_pcall(L, 0, 0, 0);
			lua_getglobal(L, "newpos");
			lua_pushnumber(L, posicao.x);
			lua_pushnumber(L, posicao.y);
			lua_pushstring(L, "up");
			
			luaL_dofile(L, "testlua.lua");
		
			lua_pcall(L, 3, 2, 0);
		
			posicao.x = (int)lua_tonumber(L, -2);
			posicao.y = (int)lua_tonumber(L, -1);
		
			lua_pop(L, 1);
		}
		if(IsKeyDown(KEY_DOWN))
		{
			lua_pcall(L, 0, 0, 0);
			lua_getglobal(L, "newpos");
			lua_pushnumber(L, posicao.x);
			lua_pushnumber(L, posicao.y);
			lua_pushstring(L, "down");
			
			luaL_dofile(L, "testlua.lua");
		
			lua_pcall(L, 3, 2, 0);
		
			posicao.x = (int)lua_tonumber(L, -2);
			posicao.y = (int)lua_tonumber(L, -1);
		
			lua_pop(L, 1);
		}

		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawCircle(posicao.x, posicao.y, 25, RED);
			DrawText(TextFormat("X: %f Y: %f", posicao.x, posicao.y), 10, 10, 12, BLUE);
		EndDrawing();
    }
	CloseWindow();
	lua_close(L);
	
    return 0;
}
