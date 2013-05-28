
// couleurs in & out
out vec4 fragColor;

in float alpha;
//in float redMul;

// mapping de texture
uniform sampler2D texId;



void main()
{

  fragColor = texture(texId, gl_PointCoord);
  fragColor.r *= 0.9;
  fragColor.g *= 0.05;
  fragColor.b *= 0.05;
  fragColor.a *= alpha;
}