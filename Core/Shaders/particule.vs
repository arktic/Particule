// matrice MVP
uniform mat4 MVP;
uniform vec3 center; // position du foyer
uniform float radius; // rayon du foyer
//uniform float radius; // position du foyer

// position initiale de cette particule. Transmis par le programme principal
in vec3 position;

// vitesse de cette particul
in vec3 velocity;

// couleur de cette particule
//in vec4 color;

//taille du point
in float size;

// temps depuis le dut de la simulation
in float t;

// position de la camera
uniform vec3 eyePosition;

// taille du viewport
uniform float viewportWidth;

in float ageRatio;

// gravit
const float g = 9.8f;


out vec4 fColor;  // interpol et transmis au fragment shader

void main() {
	vec3 np; // nouvelle position
	gl_PointSize = size *0.2* viewportWidth / length(eyePosition);
	
	// calcul de la nouvelle position
	np = position + 0.001*t * velocity;
	//np.y -= (g * t * t * 0.000001) /2;
	
	// cette nouvelle position est la position de notre particule
	gl_Position = MVP * vec4( np, 1.0f );
	
	// couleur inchangée
	fColor = color;

}