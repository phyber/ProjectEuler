#!/usr/bin/env lua
--[[
-- 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
--
-- What is the sum of the digits of the number 2^1000?
--]]
local tonumber = tonumber

local total = 0
local num = ("%.0f"):format(2^1000)

for i = 1, #num do
	total = total + tonumber(num:sub(i, i))
end

print("Total: "..total)
