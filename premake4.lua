-- Copyright (c) 2022 Matheus Klein Schaefer

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:

-- The above copyright notice and this permission notice shall be included in all
-- copies or substantial portions of the Software.

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
-- SOFTWARE.

solution "RaylibLuaPremake"
	configurations { "DebugStatic", "DebugSystem", "ReleaseStatic", "ReleaseSystem" }

	-- um projeto define um build target
	project "RaylibLuaPremake"
		kind "WindowedApp"
		language "C"
		
		files { "main.c" }

		configuration "DebugStatic"
			defines { "DEBUG" }
			defines { "BUILDSTATIC" }
			flags { "Symbols" }
			includedirs { "external/include" }
			linkoptions { "-Bstatic external/lib/libraylib.a -Bdynamic" }
			links { "m", "lua5.2", "pthread", "dl" }
            
		configuration "DebugSystem"
			defines { "DEBUG" }
			flags { "Symbols" }
			links { "raylib", "lua5.2" }

		configuration "ReleaseStatic"
			defines { "NDEBUG" }
			defines { "BUILDSTATIC" }
			flags { "Optimize" }
			includedirs { "external/include" }
			linkoptions { "-Bstatic external/lib/libraylib.a -Bdynamic" }
			links { "m", "lua5.2", "pthread", "dl" }

		configuration "ReleaseSystem"
			defines { "NDEBUG" }
			flags { "Optimize" }
			links { "raylib", "lua5.2" }
