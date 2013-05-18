#version 140


uniform mat4 MVP;

in vec3 position;
in vec3 color;
uniform int viewport_width;

out vec3 fColor;


void main()
{
  gl_Position = MVP * vec4( position, 1.0f );
  gl_PointSize = 20;
  if(gl_Position.x > 0 )
	fColor = vec3(0.8,0.8,0.8);
  else if((gl_Position.y > 0 ))
	fColor = vec3(0.4,0.4,0);
  else
	fColor = vec3(0.9,0.4,0.3);
}
