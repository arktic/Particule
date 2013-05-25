// matrice MVP
uniform mat4 MVP;
uniform vec3 center; // position du foyer
uniform float radius; // rayon du foyer
uniform vec3 eyePosition; // position de la camera
uniform float viewportWidth; // taille du viewport
uniform float sizeCoef;
// position initiale de cette particule. Transmis par le programme principal
in vec3 position;

// vitesse de cette particul
in vec3 velocity;

// couleur de cette particule
//taille du point
in float size;
// temps depuis le dut de la simulation
in float t;
in float ageRatio;
out float alpha;


//out vec4 fColor;  // interpol et transmis au fragment shader

void main() {
	vec3 np; // nouvelle position
	float s;
	s = size * (1+(sizeCoef-1)*ageRatio);
	s = s *0.2* viewportWidth / length(eyePosition);
	gl_PointSize = s;
	
	// calcul de la nouvelle position
	np = position + 0.001*t * velocity;
	//np.y -= (g * t * t * 0.000001) /2;
	
	// cette nouvelle position est la position de notre particule
	gl_Position = MVP * vec4( np, 1.0f );
	alpha = (1-2*ageRatio);

	// couleur inchangée
	//fColor = color;

}