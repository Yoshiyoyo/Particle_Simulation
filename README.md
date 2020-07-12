#
This is a program that allows the user to utilize a GUI made in Qt to create a variety of planetoids, gray particles which are affected by physics, and devices, which act on the environment.  Graphics are rendered in OpenGL. 
There are three types of devices the user can initialize.
1. Attractors: Red, These pull particles towards themselves, mass is relative to size
2. Repulsors:  Blue, pull particles away, mass is relative to size
3. Generators: Teal, randomly produce particles in a direction. Larger generators produce larger, heavier particles.

Smaller particles in this case are lighter and as a result are pulled less (smaller change in velocity) by gravitational force. 

The simulation can hold thousands of particles and devices.

Example of a few objects
![](https://i.gyazo.com/ea6f473baed47d36814a61c102cabee3.gif)


[Example with many more objects](https://i.gyazo.com/2f6a3d9f03587fd0d0ad2a1d503e13e5.gif)
