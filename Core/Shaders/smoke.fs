
// couleurs in & out
out vec4 fragColor;
in float alpha;

// mapping de texture
uniform sampler2D texId;



void main()
{
  fragColor = texture2D(texId, gl_PointCoord);
  fragColor.a *= alpha;
}