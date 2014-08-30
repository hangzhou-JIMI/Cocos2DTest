-- cclog
cclog = function(...)
    print(string.format(...))
end


-- for CCLuaEngine traceback
__G__TRACKBACK__ = function( ... )
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end


cclog("test hello lua.");
TestClass:TestLog();
cclog("test end");
--[[
local scene = CCScene:create();
local label = CCLabelTTF:create();
local layout = CCLayerColor:create(ccc4(200,200,100,28));
label:setString("ok this is label.");
scene:addChild(layout);
scene:addChild(label);
label:setPosition(200,300);
CCDirector:sharedDirector():runWithScene(scene);
]]
