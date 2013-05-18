// position initiale de cette particule. Transmis par le programme principal
in vec3 position ;

// vitesse de cette particule
in vec3 velocity ;

// couleur de cette particule
in vec3 color ;

// matrice MVP
uniform mat4 MVP ;

// temps depuis le début de la simulation
uniform float t ;

// gravité
const float g = 9.8f ;
out vec3 fColor ; // interpolé et transmis au fragment shader


void main() {
	vec3 np; // nouvelle position

	// calcul de la nouvelle position
	np = p + v*t ; 
	np.y -= g*t*t/2 ;

	// cette nouvelle position est la position de notre particule
	gl_Position = vec4(np, 1.0f) ;

	// couleur inchangée
	fColor = color ;
}