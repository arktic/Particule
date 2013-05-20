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
in vec3 color;

//taille du point
in float size;

// temps depuis le dut de la simulation
in float t;

in float ageRatio;

// gravit
const float g = 9.8f;

/*
const vec3 jaune = vec3(255,255,0);
const vec3 orange = vec3(255,165,0);
const vec3 rouge = vec3(255,0,0);
*/
out vec3 fColor;  // interpol et transmis au fragment shader

void main() {
	vec3 np; // nouvelle position
	gl_PointSize = size;
	
	//jaune - orange pour distance au centre
	/*vec3 difference = position - center;
	
	float distance = length(difference);
	if(distance < 0)
		distance = - distance;
	*/
	// calcul de la nouvelle position
	np = position + 0.001*t * velocity; // WARNING NEED TEMPS DEBUT 
	//np.y -= (g * t * t * 0.000001) /2;
	
	// cette nouvelle position est la position de notre particule
	gl_Position = MVP * vec4( np, 1.0f );
	
	// couleur "feu"
	fColor = vec3(255, 1-ageRatio*0.5 , 0 );
}