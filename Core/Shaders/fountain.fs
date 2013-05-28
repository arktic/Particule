
// couleurs in & out
out vec4 fragColor;

// mapping de texture
uniform sampler2D texId;

in float alpha;

void main()
{
  fragColor = texture(texId, gl_PointCoord);
  fragColor.r *= 0.05;
  fragColor.g *= 0.05;
  fragColor.b *= 0.9;
  fragColor.a *= alpha;
}