
-- Get references to player and ReplicatedStorage
local player = game.Players.LocalPlayer
local replicatedStorage = game:GetService("ReplicatedStorage")

-- Wait for the cheese and bomb models, and cheese pickup sound to be available in ReplicatedStorage
local cheeseModel = replicatedStorage:WaitForChild("Cheese")
local bombModel = replicatedStorage:WaitForChild("Bomb")
local cheesePickupSound = replicatedStorage:WaitForChild("CheesePickupSound")
local explosionSound = replicatedStorage:WaitForChild("ExplosionSound") -- Assume there's an explosion sound

-- Create leaderstats and add a counter for cheese collected
local leaderstats = Instance.new("Folder")
leaderstats.Name = "leaderstats"
leaderstats.Parent = player

local cheeseCounter = Instance.new("IntValue")
cheeseCounter.Name = "CheeseCollected"
cheeseCounter.Value = 0
cheeseCounter.Parent = leaderstats

-- Function to spawn cheese above the player at random locations
local function spawnCheese()
	-- Wait for the player's character to be loaded
	local character = player.Character or player.CharacterAdded:Wait()
	

	-- Wait for the HumanoidRootPart to be available in the character
	local humanoidRootPart = character:WaitForChild("HumanoidRootPart")
	

	-- Create a clone of the cheese model
	local cheese = cheeseModel:Clone()
	

	-- Calculate a random position above the player
	local randomX = math.random(-10, 10)
	local randomZ = math.random(-10, 10)
	local spawnPosition = humanoidRootPart.Position + Vector3.new(randomX, 50, randomZ)


	-- Ensure the cheese is visible and anchored initially
	cheese.Position = spawnPosition
	cheese.Anchored = true  -- Initially anchor the cheese
	cheese.Parent = workspace

	-- Add a delay to ensure visibility, then unanchor to let it fall
	wait(0.1)
	cheese.Anchored = false

	-- Add a touch event to collect the cheese
	cheese.Touched:Connect(function(hit)
		local hitPlayer = game.Players:GetPlayerFromCharacter(hit.Parent)
		if hitPlayer == player then
			-- Destroy the cheese
			cheese:Destroy()
			-- Update the cheese collected counter
			cheeseCounter.Value = cheeseCounter.Value + 1
			
			-- Play the cheese pickup sound
			local sound = cheesePickupSound:Clone()
			sound.Parent = player.Character
			sound:Play()
			-- Destroy the sound after it finishes playing
			sound.Ended:Connect(function()
				sound:Destroy()
			end)
		end
	end)

	-- Destroy the cheese after 30 seconds if not collected
	delay(30, function()
		if cheese and cheese.Parent then
			cheese:Destroy()
			
		end
	end)
end

-- Function to spawn bomb above the player at random locations
local function spawnBomb()
	-- Wait for the player's character to be loaded
	local character = player.Character or player.CharacterAdded:Wait()
	

	-- Wait for the HumanoidRootPart to be available in the character
	local humanoidRootPart = character:WaitForChild("HumanoidRootPart")
	

	-- Create a clone of the bomb model
	local bomb = bombModel:Clone()
	

	-- Calculate a random position above the player
	local randomX = math.random(-10, 10)
	local randomZ = math.random(-10, 10)
	local spawnPosition = humanoidRootPart.Position + Vector3.new(randomX, 50, randomZ)
	

	-- Ensure the bomb is visible and anchored initially
	bomb.Position = spawnPosition
	bomb.Anchored = true  -- Initially anchor the bomb
	bomb.Parent = workspace

	-- Add a delay to ensure visibility, then unanchor to let it fall
	wait(0.1)
	bomb.Anchored = false

	-- Add a touch event to handle bomb explosion
	bomb.Touched:Connect(function(hit)
		local hitPlayer = game.Players:GetPlayerFromCharacter(hit.Parent)
		if hitPlayer then
			-- Create an explosion at the bomb's position
			local explosion = Instance.new("Explosion")
			explosion.Position = bomb.Position
			explosion.BlastRadius = 10
			explosion.BlastPressure = 500000
			explosion.Parent = workspace

			-- Play the explosion sound
			local sound = explosionSound:Clone()
			sound.Parent = bomb
			sound:Play()

			-- Damage the player if within the blast radius
			hitPlayer.Character:BreakJoints()

			-- Destroy the bomb after explosion
			bomb:Destroy()
		end
	end)

	-- Destroy the bomb after 30 seconds if not exploded
	delay(30, function()
		if bomb and bomb.Parent then
			bomb:Destroy()
			
		end
	end)
end

-- Loop to spawn cheese and bombs at specific intervals
while true do
	if math.random() < 0.5 then
		spawnBomb()
	else
		spawnCheese()
	end
	wait(1)  -- Spawn cheese or bomb every 1 second
end
