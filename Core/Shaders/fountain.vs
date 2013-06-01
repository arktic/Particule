// matrice MVP
uniform mat4 MVP;
uniform vec3 eyePosition; // position de la camera
uniform float viewportWidth; // taille du viewport

// position initiale de cette particule. Transmis par le programme principal
in vec3 position;

// vitesse de cette particul
in vec3 velocity;

//taille du point
in float size;

// temps depuis le dut de la simulation
in float t;

in float ageRatio;
out float alpha;

const float g = 4;

void main() {
	vec3 np; // nouvelle position
	gl_PointSize = size *0.2* viewportWidth / length(eyePosition);
	
	// calcul de la nouvelle position
	np = position + 0.001*t * velocity;
	np.y -= (g * t * t * 0.000001) /2;
	
	gl_Position = MVP * vec4( np, 1.0f );
	float start = 0.2;
	float end = 0.5;
	if(ageRatio < start) {
		alpha = ageRatio * 1/start;
	}
	else if (ageRatio > end) {
		alpha = 1-((ageRatio-end) * 1/(1-end));
	}
	else
		alpha = 1;
}