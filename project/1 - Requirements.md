**Requirement Analysis for miniRT - RayTracing Program**

1. **Objective:**
   - The goal is to develop a program, "miniRT," that generates computer-generated images representing scenes with specific geometric objects and lighting systems using the Raytracing protocol.

2. **Functionality:**
   - The program must utilize the miniLibX library for graphical output.
   - It should handle simple geometric objects: plane, sphere, and cylinder.
   - Correctly handle intersections and the inside of objects.
   - Support resizing of objects (diameter for a sphere, width and height for a cylinder).
   - Implement translation and rotation transformations for objects, lights, and cameras.
   - Manage lighting, including spot brightness, hard shadows, and ambient and diffuse lighting.
   - Display the rendered image in a window with fluid window management.

3. **User Interface:**
   - The program should provide a smooth window management experience, including switching, minimization, and resolution changes.
   - Interaction with the program should follow standard conventions, such as pressing ESC to exit the program and clicking on the red cross to close the window.

4. **Scene Description File:**
   - The program should take a scene description file with a ".rt" extension as its first argument.
   - Elements in the file can be separated by line breaks and information within each element by spaces.
   - Each type of element (ambient lighting, camera, light, sphere, plane, cylinder) should be declared in any order.

5. **Scene Elements Specification:**
   - **Ambient Lighting (A):**
      - Ambient lighting ratio in the range [0.0, 1.0].
      - RGB colors in the range [0-255].

   - **Camera (C):**
      - Viewpoint coordinates (x, y, z).
      - 3D normalized orientation vector (x, y, z).
      - Horizontal field of view (FOV) in degrees.

   - **Light (L):**
      - Light point coordinates (x, y, z).
      - Light brightness ratio in the range [0.0, 1.0].
      - RGB colors (unused in the mandatory part).

   - **Sphere (sp):**
      - Sphere center coordinates (x, y, z).
      - Sphere diameter.
      - RGB colors.

   - **Plane (pl):**
      - Point in the plane coordinates (x, y, z).
      - Normalized normal vector.
      - RGB colors.

   - **Cylinder (cy):**
      - Cylinder center coordinates (x, y, z).
      - Normalized vector of the axis of the cylinder.
      - Cylinder diameter and height.
      - RGB colors.

6. **Error Handling:**
   - The program should exit gracefully with an "Error\n" message and an explicit error message of choice if any misconfiguration is encountered in the scene file.

7. **Testing:**
   - The defense should include a set of scenes focusing on functional aspects to facilitate the evaluation of created elements.

This requirement analysis provides a foundation for the development of the miniRT program, ensuring that it meets the specified objectives and user expectations           .  