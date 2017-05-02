### Testing Grounds Introduction ###

+ Welcome, fresh start, new energy
+ Did you go back and modify Building Escape? 
+ Most ambitious section yet 
+ Bookmark the live Google Slides 
+ Comment on the slides, especially typos 
+ Come say hi at [community.gamedev.tv](https://community.gamedev.tv)

### Code Architecture Storing State ###



### Testing Grounds GDD ###

+ The concept of the game
+ The rules of the game
+ Some of the asset requirements for the game
+ Identify possible technical challenges.

### Using Git LFS (Large File Support) ###

+ The distinction between Git vs GitHub
+ Use Unreal’s toolbar & SourceTree 
+ Enable Git Large File Support (LFS) 
+ Setup on GitHub (no readme.md or initial commit) 
+ Push to GitHub and share
+ Warning: may take a while on slow broadband.

### Marketing & Markdown ###

+ Limitations of Unreal’s connection to GitHub
+ How to reset to previous commit to combine 
+ Presenting your public GitHub page well 
+ Using Markdown to enrich formatting.

### Use git clean to Revert Project ###

+ Upgrading my project to Unreal 4.13
+ An overview of the scene 
+ How the First Person Character is composed 
+ Adding a spiral staircase.

### First Person Character Overview ###



### The Third Person Character ###

+ Add a third person character to the scene
+ Caution about tidying files at this stage 
+ Add a navmesh, and check it’s continuous.

### Introducing AI Behaviour Trees ###

+ Setup a Blueprint AI controller class
+ Behaviour Trees controll AI execution flow 
+ Blackboards hold AI instance data 
+ How to associate a behaviour tree with an AI 
+ Testing that our behavior tree is running.

### Introducing AI Blackboard Data ###

+ Blackboard data is like member variables in code
+ Using blackboard data to set patrol points 
+ Practice setting blackboard values in Blueprint 
+ Test simple AI patrol behaviour.

### Target Points and Patrol Routes ###

+ Add a variable to the NPC’s blueprint
+ How to make a variable an array in blueprint 
+ Introducing Target Point actors 
+ Using target points to specify patrol routes.

### Using Any Actor for Waypoints ###

+ Actors are more general than target points
+ How to select an actor from another actor 
+ Getting the AI Controller to set Blackboard data 
+ Testing our characters go to a set waypoint.

### Options for Grouping Actors ###

+ Use layers (usually used for visibility)
+ Use groups as a simple multi-select tool 
+ Use tags, can be flexible but easy to forget 
+ Use a parent Empty Actor, or a Folder 
+ Group on game object (e.g. array on NPC) 
+ The key is to know the pros and cons.

### Blueprint Behaviour Tree Tasks ###

+ How to use Blackboard Key Selector variables
+ Creating new Tasks in Behaviour Trees 
+ Pseudocode programming in Blueprint 
+ How to use the Execute AI node 
+ How to use the Finish Execute node.

### Modular Arithmetic & Cycles ###



### Performance Profiling 101 ###

+ The first rule of performance: “profile first”
+ Access profiler from Window > Developer Tools 
+ Choose Session Front End 
+ Select your running game session 
+ Chose Profiler tab, and hit Data Preview 
+ Search for your function and double-click.

### C++ AI Behaviour Tree Tasks ###

+ Add “AIModule” and “GameplayTasks” to build
+ Inherit C++ class from **UBTTaskNode**
+ Override **ExecuteTask()**
+ Return **EBTNodeResult::Succeeded;**
+ Don’t try and extend in Blueprint 
+ Use Blueprint XOR C++ for a given task.

### Reading Blackboard Data in C++ ###

+ Expose a blackboard key selector in C++
+ **#include “BehaviorTree/BlackboardComponent.h”**
+ **OwnerComp.GetBlackboardComponent()**
+ Use **GetValueAsInt()** etc to get the value 
+ You can now access blackboard data in C++.

### The Consequences of Inheritance ###

+ We have coupled our AI ChoseNextWaypoint task to the Third Person Character.
+ We have also specialised our Blueprint class with a variable, PatrolPoints. 
+ These dependencies are undesirable, but we will proceed with our conversion.

### Converting Blueprint to C++ ###

+ **OwnerComp.GetAIOwner()** to get AI Controller
+ If you’re casting, you’re probably coupling 
+ Use **.Num()** to get number of elements in **TArray**
+ Use **TODO** for reminders, to help you FOCUS 
+ FOCUS = Follow One Course Until Successful.

### Composition over Inheritance ###

+ We created PatrollingGuard by inheritance
+ How about if we want a patrolling tank? 
+ Another option is to use an actor component 
+ This is an age-old debate 
+ Let’s get some real-world experience of the two 
+ Convert to a component model.

### Talking Head: What We've Covered So Far ###

+ What we've covered recently
+ What's coming up.

### How to Delete a C++ Class ###

+ Yes it should be easier than this, tell Epic!
+ How to remove CPP files from browser in Unreal 
+ The process for deleting C++ classes.

### Instanced Materials ###

+ Also called Material Instances
+ These allow modification with little overhead 
+ How to create an instanced material.

### Introducing AI Perception ###

+ Use AI Perception, it’s newer than Pawn Sensing
+ How to add AI Perception to your controller 
+ Use the apostrophe key ‘ to enable AI debug 
+ Remember Shift + F1, F8, F11 etc.

### OnTargetPerceptionUpdated Event ###

+ Use the On Target Perception Updated event
+ This reports the actor sensed 
+ And the class of the sense (e.g. sight, hearing) 
+ How to setup perception events.

### AI Hearing Perception in Unreal ###

+ Hearing is a sense that compliments sight
+ How to set up AI Perception hearing sense 
+ How to get hearing perception to trigger 
+ Making your actor create a noise.

### The Animation Starter Pack ###

+ The skeleton comprises the bones
+ Over the skeleton lays a skeletal mesh 
+ Each vertex of the mesh connects to bone(s) 
+ The animation tells the bones how to move 
+ The bones tell the mesh how to move 
+ The Animation BP controls the animations.

### Changing a Character’s Animation ###

+ How to change a mesh’s animation class
+ Matching the animation’s mesh to… 
+ … the mesh selected on the character 
+ You can apply instance changes to blueprint 
+ However be careful what you take with you 
+ Solving “can’t save… graph is linked” error.

### Customising a Character Blueprint ###

+ You can start with a off-the-shelf blueprint
+ We can then add our reusable components 
+ Another way of getting our desired character.

### Sub Behaviour Trees ###

+ Behaviour trees can get complex
+ We want to keep a consistent level of abstraction 
+ Behaviour trees can run “sub” trees 
+ This helps us organise our project.

### Talking Head - Introducing Sam ###

+ Congratulations on getting this far in the course.
+ Recapping the AI work we have done so far.
+ Introducing the new instructor for the section: Sam.

### Talking Head - Refactoring Superpowers ###

+ Why refactoring is so important.
+ Refactor skills give you the edge.
+ What’s coming up in the next lectures.

### Simplifying Our Project ###

+ Deleting and Moving folders.
+ Ensuring deletion on the file-system.
+ Good file structure for Unreal.
+ Viewing the dependencies of an object.
+ How and when to fix redirectors.

### Renaming & Moving CPP ###

+ Renaming CPP files.
+ How to deal with renaming blueprint parents.
+ Refactor class names in CPP.
+ Updating .generated.h files.

### Solution: Renaming & Moving CPP ###

+ Repeating the renaming process.
+ Finishing our refactor.
+ Fixing CDO Constructor errors.

### Holding a Gun with Skeletal Sockets ###

+ Reading existing source code for hints.
+ Creating a socket on a skeletal mesh.
+ Parenting a gun to that socket.
+ Removing unused assets.

### Understanding Animation Blueprints ###

+ The major components.
+ How to preview animations.
+ Definition of an animation and pose.
+ Understanding the AnimGraph.
+ Playing a custom animation.

### Creating Animation State Machines ###

+ Why state machines?
+ What are state machines?
+ What’s inside a UE4 state?
+ How to add transitions.
+ Adding a shooting state.

### Movement Blend Spaces ###

+ What is a blend space?
+ How to create a movement blend space.
+ Examining the existing Jog blend space.
+ Replicating for Ironsights.

### Offset Animations ###

+ Creating an offset animation.
+ Applying an offset to a base.
+ Conditional blend nodes.

### Aiming Blend Spaces Offsets ###

+ Aim offset assets.
+ 1D vs 2D Aim offsets.
+ Editing an existing animation sequence.

### Rotating with SetFocalPoint() ###

+ Revising Behaviour Tree tasks.
+ Making our character face us.
+ Using AIController’s SetFocalPoint()

### Character Movement vs Rotation ###

+ More code reading.
+ Jumping between files in Visual Studio.
+ Difference between movement and rotation.
+ Mapping out complex systems.

### Control Rotation for Aim ###

+ Getting the control rotation.
+ Focus Actor vs Focal Point
+ Splitting rotators and setting pitch.
+ Controlling Animation BP properties.

### Behaviour Tree Decorators ###

+ Creating a decorator.
+ Sequence vs Select nodes.
+ Aborting decorators early.
+ Clearing blackboard keys from blueprint.
+ Patrolling, agro and following.

### Behaviour Tree Services ###

+ Using decorators vs services.
+ Creating a service.
+ Deeper into behaviour tree states.
+ How to implement suspicion.
+ Giving our character breathing space.
+ Comparing BP Validity and NULL.

### Tweaking AI Behaviour ###

+ Preventing Behaviour Tree flicker.
+ Creating mutually exclusive states.

### Debugging AI Behaviour ###

+ Viewing behaviour while playing.
+ Using tags on Actors.
+ Revising interrupting tasks.
+ Adding in multiple actors.

### Refactoring to a Gun Actor ###

+ Create a Gun actor.
+ Move the firing code over.
+ Revising refactoring.

### Attaching Actors to Components ###

+ Revise spawning child actors.
+ Attaching actors to sub-components.
+ Attachment rule to sockets.

### Configuring the Gun ###

+ Playing montage animations.
+ Connecting to actors in code.
+ Finishing our refactor.

### Moving Files from LFS to Git ###

+ The pros and cons of LFS.
+ How to move files from LFS.
+ Tracking folder instead of extensions.
+ Where tracking happens.

### To LFS or Not to LFS? ###

+ The pros and cons of LFS.
+ Organising your project for clarity.
+ How to deal with .umap assets.

### Child Actor Components ###

+ Previewing the gun with the skeleton.
+ Positioning the gun.
+ Child actors with Blueprint.
+ Using Child Actor Components.

### Introduction to Inverse Kinematics ###

+ Local vs component-space poses.
+ Understanding bone-space.
+ The principles of IK.
+ End effectors and Joint targets.
+ Mapping to the Two Bone IK node.

### Inverse Kinematics with Animations ###

+ Using the Two Bone IK node.
+ Effectors vs Joint targets

### Comparing Blueprints with Diffs ###

+ Using UE4 built-in version control.
+ Diffing blueprints.
+ LFS vs Git assets in editor.

### Boolean Blending for Aim States ###

+ Boolean blending in Unreal.
+ Setting variables in animation BP.
+ Making the AI aim.

### Adding Firing Animations ###

+ When to use additive identities.
+ Blending additive animations.
+ Creating an additive firing animation.
+ Controlling firing from the AI.

### Animation Notify Events ###

+ Synchronising sound and animation.
+ Creating custom notify events.
+ Hooking up our gun trigger to AI.

### Taking Damage in Blueprint ###

+ Applying damage from a projectile.
+ Taking damage in a BP character.
+ Detaching a controller from a Pawn.

### Death Animations and Refactors ###

+ Revision of BP refactoring.
+ Making our Animation BP clean.
+ Death animations on the AI.

### Switching 1st and 3rd Person ###

+ Swapping out a 1st to 3rd person character.
+ Wrapping rotations.

### Owner Invisible Meshes ###

+ Own See vs Owner no see meshes.
+ Why 1st person Meshes.
+ Hooking up Fire input in TPCharacter.

### Separating Firing from Gun Meshes ###

+ Why we need two gun meshes.  
+ Creating Blueprint components.  
+ Scene components vs Actor components.  
+ Camera rotation with control rotation.

### Aiming Our 1st Person Camera ###

+ Local vs Global rotation.
+ UE4 optimizations for unpossesed characters.

### Architecture of Infinite Runners ###

+ Using the Arrow component.
+ How to architect an infinite runner.
+ Overview of how we want our levels to work.

### Spawning Terrain in the GameMode ###

+ GameMode BP vs Level BP
+ Creating a blueprint GameMode
+ How to spawn tiled terrain.
+ Using a blueprint for-loop.

### Level Gating for Testing Grounds ###

+ Why we need level gating. 
+ Our approach to gating. 
+ Enabling/disabling collisions.

### Swapping Materials in Blueprint ###

+ Creating material instances. 
+ Exposing material parameters. 
+ Swapping materials in blueprint. 
+ Adding affordance to our barriers.

### Garbage Collecting Previous Tiles ###

+ When to delete previous tiles. 
+ How to get hold of the Game Mode. 
+ Spawning new tiles when needed. 
+ Keeping the minimal tiles in memory.

### Merging Our TP and FP Files ###

+ Fix camera glitch while strafing.
+ Merge the NPC and Player folders.
+ Revise redirectors.
+ Revise folder movement and deletion.

### Hit vs Overlap Events ###

+ Debug a projectile spawn issue.
+ Overview the collision system.
+ Understand hit and overlap notifications.
+ Review different Collision Presets

### Dynamically Calculating NavMesh ###

+ NavMesh and procedural terrain.
+ Dynamic NavMesh generation.
+ When LFS shouldn’t be used.

### Keep It Simple Stupid ###

+ Make the player tough for testing.
+ Deeply understand the AI system.
+ When is code too complex to debug?
+ Write high level pseudo code.

### Parallel Behaviour Tree Tasks ###

+ Parallel actions in Behaviour Trees.
+ Pseudocode-lead refactoring.
+ Aborting lower priority with decorators.
+ Organising conditional Behaviour Trees.

### Custom BT Tasks and Decorators ###

+ Implementing a conditional decorator.
+ Custom task nodes.
+ Clean up when task node is aborted.

### External Build Data in 4.14+ ###

+ Updating to 4.15.0
+ Storing build data outside of .umaps.

### Physical Gun Architecture ###

+ Renaming to style guide
+ Problems of our existing architecture
+ Improved gun-centric architecture
+ Challenge: reinstating the gun actor.

(Unique Video Reference: 76_TG_URC)

### Converting a Character BP to C++ ###

+ Creating and reparenting a character
+ Challenge: Converting the component hierarchy
+ Reviewing my Mannequin.cpp

(Unique Video Reference: 77_TG_URC )

### Who’s Pulled the Trigger? ###

+ Reviewing the architecture
+ Revision: binding input in C++
+ Challenge
+ Remove firing from Animation BP
+ Control trigger from AI

(Unique Video Reference: 78_TG_URC)

### Cooldown Nodes & Gameplay Tags ###

+ How cooldown nodes work.
+ Adding gameplay tags.
+ Challenge: Let the AI Cooldown
+ Randomised burst of fire.
+ Separated into sub-behaviour trees.

(Unique Video Reference: 79_TG_URC)

### Animation Montages and Slots ###

+ What is an animation slot?
+ How to blend by root bone.
+ "Caching" a pose.
+ Challenge: Create and Play Firing Montage

(Unique Video Reference: 80_TG_URC)

### Reattaching the Gun ###

+ Attach gun to correct mesh if player
+ Reattach gun when player dies
+ Challenge: Play Two Montages

(Unique Video Reference: 81_TG_URC )
