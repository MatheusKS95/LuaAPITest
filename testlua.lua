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


function newpos(x, y, direction)
	--print(x, y, direction);
	if string.match(direction, "up") then
		y = y - 1;
	elseif string.match(direction, "down") then
		y = y + 1;
	elseif string.match(direction, "right") then
		x = x + 1;
	elseif string.match(direction, "left") then
		x = x - 1;
	elseif string.match(direction, "none") then
		x = x; y = y;
	end
	
	if(x >= 800) then
		x = x - 1;
	end

	if(x <= 0) then
		x = x + 1;
	end

	if(y >= 600) then
		y = y - 1;
	end

	if(y <= 0) then
		y = y + 1;
	end
	
	return x, y;
end
