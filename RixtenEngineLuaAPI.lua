---@meta
-- API

--- Ready function
--- run during initialization
function on_init() end

--- Tick function
--- run during tick
--- @param deltaTime integer current deltaTime
function on_tick(deltaTime) end 

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
---@field set_size fun(self: Window, width: integer, height: integer) Set window size
---@field set_title fun(self: Window, title: string) Set window title
