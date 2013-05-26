// matrice MVP
uniform mat4 MVP;
uniform vec3 center; // position du foyer
uniform float radius; // rayon du foyer
uniform vec3 eyePosition; // position de la camera
uniform float viewportWidth; // taille du viewport

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
in float ageRatio;

//out vec4 fColor;  // interpol et transmis au fragment shader

void main() {
	vec3 np; // nouvelle position
	gl_PointSize = size *0.2* viewportWidth / length(eyePosition);
	
	// calcul de la nouvelle position
	np = position + 0.001*t * (velocity);
	
	// cette nouvelle position est la position de notre particule
	gl_Position = MVP * vec4( np, 1.0f );
}