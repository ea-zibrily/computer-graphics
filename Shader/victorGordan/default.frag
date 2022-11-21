version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;


//exercise 2
uniform float scale;

void main()
{
	//excercise 2 color
	FragColor = vec4(color.x * scale,color.y * scale, color.z * scale, 1.0f);
	//FragColor = vec4(color, 1.0f);
}
Footer
© 2022 GitHub, Inc.