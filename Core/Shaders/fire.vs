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
out int alive;

//out vec4 fColor;  // interpol et transmis au fragment shader
//out float redMul;
out float alpha;

void main() {
	vec3 np; // nouvelle position
	alive = 1;
	vec3 d;
	d.x = position.x - center.x;
	d.y = position.y - center.y;
	d.z = position.z - center.z;
	float h = position.y - center.y;
	if(length(d) > (radius) && h < radius  )
		alive = 0;
	gl_PointSize = size *0.2* viewportWidth / length(eyePosition);
	
	// calcul de la nouvelle position
	np = position + 0.001*t * (velocity);
	
	// cette nouvelle position est la position de notre particule
	gl_Position = MVP * vec4( np, 1.0f );
	//float d = length(center-position);
//	if(d > radius*0.8) {
//		redMul = 1.2;
//	}
	
	float start = 0.2;
	float end = 0.8;
	if(ageRatio < start) {
		alpha = ageRatio * 1/start;
	}
	else if (ageRatio > end) {
		alpha = 1-((ageRatio-end) * 1/(1-end));
	}
	else
		alpha = 1;
}