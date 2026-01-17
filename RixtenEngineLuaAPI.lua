---@meta
-- API

--- Engine object
RixtenEngine = {}

--- Create Window
---@param width integer 
---@param heigth integer
---@param title string
---@return Window window The created window object
function RixtenEngine.create_window(width, heigth, title) end

--- Window class
---@class Window
---@field is_open fun() boolean Check if window is open
---@field update fun() Swap window buffers