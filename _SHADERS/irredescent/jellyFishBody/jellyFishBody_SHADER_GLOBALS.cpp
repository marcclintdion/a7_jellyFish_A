GLfloat     jellyFishBody_LIGHT_POSITION_01[] =  {43.2259, 52.5437, 26.15, 1};
GLfloat     jellyFishBody_LIGHT_POSITION_02[] = {  -30.5,  100, 12.5, 1.0};
GLfloat     jellyFishBody_LIGHT_POSITION_03[] = {  -2.505,  -100,   0.0, 1.0};
GLfloat     jellyFishBody_LIGHT_POSITION_04[] = {  -0.005,   0.5,   5, 1.0};

//----                                                                                                
GLuint      UNIFORM_LIGHT_POSITION_01_jellyFishBody; 
GLuint      UNIFORM_LIGHT_POSITION_02_jellyFishBody;        
GLuint      UNIFORM_LIGHT_POSITION_03_jellyFishBody; 
GLuint      UNIFORM_LIGHT_POSITION_04_jellyFishBody; 

//------------------------------------------------  

GLfloat     jellyFishBody_ATTENUATION         =    0.72;
GLfloat     jellyFishBody_SHININESS           =   1083.00;

GLuint      jellyFishBody_SHADER_VERTEX;                                                                                                      
GLuint      jellyFishBody_SHADER_FRAGMENT;                                                                                                    
GLuint      jellyFishBody_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_jellyFishBody;  
GLuint      UNIFORM_MODELVIEW_jellyFishBody;                                                                                             
//----
GLuint      UNIFORM_SHADOW_PROJ_jellyFishBody;   
GLuint      UNIFORM_modelViewShadow_jellyFishBody; 
//----
GLuint      UNIFORM_viewMatrix_jellyFishBody; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_jellyFishBody;  
GLuint      UNIFORM_textureMatrix_jellyFishBody;
GLuint      UNIFORM_INVERSEMATRIX_jellyFishBody;
                                                                                  
//------------------------------------------------  


GLuint      UNIFORM_SHININESS_jellyFishBody; 
GLuint      UNIFORM_GENERIC_jellyFishBody; 

GLuint      UNIFORM_zDirBias_jellyFishBody;  
GLuint      UNIFORM_TEXTURE_LightMap_jellyFishBody;
GLuint      UNIFORM_TEXTURE_SHADOW_jellyFishBody;                                                                                              
GLuint      UNIFORM_TEXTURE_HEIGHT_jellyFishBody;
GLuint      UNIFORM_TEXTURE_DOT3_jellyFishBody;
GLuint      UNIFORM_TEXTURE_jellyFishBody;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     jellyFishBody_POSITION[]            =  {  0.0, 0.0,  0.0, 1.0};                                                                    
GLfloat     jellyFishBody_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     jellyFishBody_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
