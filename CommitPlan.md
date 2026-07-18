# Commit 5:
## 5.1: World Generator Module
- Make a world-gen module with basic functions.

## 5.2: Noise functions(s)
- Make a math module and create an extremely small Perlin/Simplex noise implementation.

## 5.3: Terrain height
- Use height generated from the noise functions to determine which block is to be placed in the terrain generation.

## 5.4: Seed
- A single value to generate the exact same world for the noise functions. 

## 5.5: Better Terrain 
- Add FBM and multiple octaves.
- Increase chunk dimensions to get the best results for this commit.

## 5.6: Biome groundwork
- Structure the code to make the world-gen module capable of biomes
- Only groundwork, no actual biomes.

---

# Commit 6:
## 6.1: World
- Introduce a `World` struct, with chunk storage and seeds and stuff.

## 6.2: Multiple chunks 
- Generate and show multiple chunks.

## 6.3: Chunk coordinates
- Add positions to `Chunk`
- Add functions to convert world space coordinates to chunk space coordinates

## 6.4: World generation 
- Generate each chunk in the `World` but keep it small.
- Integrate terrain generation across chunks.

## 6.5: World Rendering
- World becomes responsible for generating meshes for the chunks.
- Maybe even try to have one draw call for the whole `World` by chaining meshes together.

---

# Plans for Later:
- Greedy meshing
- Frustum culling
- Ambient occlusion for block faces
- Trees
- Caves
- Water
- Chunk streaming
- Multithreading
- World saving/loading
- Block placing/breaking 