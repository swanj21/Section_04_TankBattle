# Section_04_TankBattle
The Tank Battle game that is created for the GameDev.tv course.

## Game Design Document

### Concept
Drive around a tank while avoiding enemy fire and using your own weapons to defeat the enemies.  
You have a limited number of shots but can refill if you drive over an ‘ammo’ pickup.  
If you get hit by the enemy fire you will lose health, and if it falls to 0 then you lose.  
You can replenish your health by driving over a ‘health’ pickup.  
To win, destroy all of your opponents before you are destroyed by them.

### Rules

- You win by defeating all of your opponents

- You lose by taking enough damage that your tank is destroyed

- You are allowed to

  - Drive your tank around the terrain
  - Forwards and backwards only(like an actual tank), not side to side
  - Aim your cannon
  - Horizontally and vertically up to a limit
  - Fire your cannon
  - Once every x number of seconds
  - Only when you have ammo left
  - Drive over objects that
    - Replenish your ammo
    - Replenish your health
 
- You are not allowed to

  - Aim your cannon past a preset limit
  - Fire faster than the allowed times/second
  - Fire when you have 0 ammo
  - Have more than
    - A set amount of ammo
    - A set amount of health
 

- The AI opponents are allowed to

  - Drive their tank around the terrain
  - Forwards and backwards only(like an actual tank), not side to side
  - Aim their cannon
  - Horizontally and vertically up to a limit
  - Fire their cannon
  - Only every x number of seconds depending on the type of tank they are
  - Only when they have ammo left
 

- The AI opponents are not allowed to

  - Drive over objects that
  - Replenish their ammo
  - Replenish their health
  - Aim their cannon past a preset limit
  - Fire faster than the allowed times/second
  - Fire when they have 0 ammo
  - Have more than
    - A set amount of ammo
    - A set amount of health
 

### Requirements

- Sound FX

  - Tank
    - Moving
    - Shooting
    - Being destroyed
    - Being repaired
    - Trying to fire with no ammo
  - Projectile
    - Flying through the air
    - Hitting something other than a tank
    - Hitting a tank
  - Ammo being replenished
 

### Art

- Meshes and textures
  - User tank
  - AI tank
    - Weak
    - Medium
    - Strong
  - Projectile
- Terrain
  - Basic structure
  - Hills
  - Mountains
  - Grass
  - Dirt
- Particles
  - Projectile
    - Flying through the air
    - Hitting something other than a tank
    - Hitting a tank
- Tank
  - Firing projectile
  - Being destroyed

### Music

- Background music
  - When not engaging anyone
  - When engaging an enemy
