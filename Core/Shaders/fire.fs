#version 140

// couleurs in & out
out vec4 fragColor;

// mapping de texture
uniform sampler2D texId;



void main()
{
  fragColor = texture(texId, gl_PointCoord);
}