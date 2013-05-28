
// couleurs in & out
out vec4 fragColor;
in int alive;

// mapping de texture
uniform sampler2D texId;



void main()
{
  if(alive == 0)
	discard;
  fragColor = texture(texId, gl_PointCoord);
}