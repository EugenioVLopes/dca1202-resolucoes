#ifndef SCULPTOR_HP
#define SCULPTOR_HP

struct Voxel {
  float r,g,b; // Cores: Vermelhor, Verde, Azul
  float a;     // Trasnparencia
  bool show;   // Propriedade que determina se será exibido  Incluido ou nao
};

class Sculptor {
  private: 
    Voxel ***v;    // 3D matrix
    int nx,ny,nz;  // Dimensions
    float r,g,b,a; // Current drawing color
  public:
    Sculptor(int _nx, int _ny, int _nz); // Construtor
    ~Sculptor(); // Destrutor
    void setColor(float r, float g, float b, float a); // Método que defini a cor 
    void putVoxel(int x, int y, int z); // Método que 'coloca' um voxel
    void cutVoxel(int x, int y, int z); // Método que 'corta' um voxel
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // Método que 'coloca' uma caixa/cubo
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // Método que 'corta' uma caixa/cubo
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); // Método que 'coloca' uma esfera
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); // Método que 'corta' uma esfera
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Método que 'coloca' uma elipsoide
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Método que 'corta' uma elipsoide
    void writeOFF(const char* filename); // Método que salva a escultura em um arquivo OFF
};

#endif