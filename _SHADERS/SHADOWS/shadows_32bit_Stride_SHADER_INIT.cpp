    
    SHADER_shadow_32bit_Stride = glCreateProgram();
    //---------------------------------------------------- 
const GLchar *vertexSource_shadow_32bit_Stride =

"    #define highp                                                                                                                              \n"

"    uniform      mat4  ModelViewProjection;                                                                                                    \n"
"    attribute    vec4  position;                                                                                                               \n"



"    void main()                                                                                                                                \n"
"    {                                                                                                                                          \n"                                                                            

"         gl_Position                =  ModelViewProjection * position;                                                                         \n"

"    }\n";

    //---------------------------------------------------------------------

const GLchar *fragmentSource_shadow_32bit_Stride =     

" #ifdef GL_ES                                                                                                                                  \n"
" #else                                                                                                                                         \n"
" #define highp                                                                                                                                 \n"
" #endif                                                                                                                                        \n"


"     void main()                                                                                                                               \n"
"     {                                                                                                                                         \n"


"         gl_FragColor = highp vec4(1.0, 1.0, 1.0, 1.0);                                                                                              \n"         


"    }\n";
    //--------------------------------------------------------------------------------------------------------------------------------------   
    SHADER_VERTEX_shadow_32bit_Stride = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( SHADER_VERTEX_shadow_32bit_Stride, 1, &vertexSource_shadow_32bit_Stride, NULL );
    glCompileShader( SHADER_VERTEX_shadow_32bit_Stride);

    //----------------------------------------------------        
    SHADER_FRAGMENT_shadow_32bit_Stride = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource( SHADER_FRAGMENT_shadow_32bit_Stride, 1, &fragmentSource_shadow_32bit_Stride, NULL );
    glCompileShader(SHADER_FRAGMENT_shadow_32bit_Stride);
       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glAttachShader( SHADER_shadow_32bit_Stride, SHADER_VERTEX_shadow_32bit_Stride );
    glAttachShader( SHADER_shadow_32bit_Stride, SHADER_FRAGMENT_shadow_32bit_Stride );
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   0, "position");    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   1, "normal");    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   2, "texture");       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glDeleteShader(SHADER_VERTEX_shadow_32bit_Stride);
    glDeleteShader(SHADER_FRAGMENT_shadow_32bit_Stride);   
    glLinkProgram( SHADER_shadow_32bit_Stride);  
    //--------------------------------------------------------------------------------------------------------------------------------------  
  
    UNIFORM_MODELVIEW_shadow_32bit_Stride               = glGetUniformLocation(SHADER_shadow_32bit_Stride, "ModelView");  
    UNIFORM_MODELVIEWPROJ_shadow_32bit_Stride           = glGetUniformLocation(SHADER_shadow_32bit_Stride, "ModelViewProjection");
    UNIFORM_MODELVIEWPROJ_INVERSE_shadow_32bit_Stride   = glGetUniformLocation(SHADER_shadow_32bit_Stride, "ModelViewProjectionInverse");    
    UNIFORM_LIGHT_MATRIX_shadow_32bit_Stride            = glGetUniformLocation(SHADER_shadow_32bit_Stride, "LightMatrix");        
    UNIFORM_offset_shadow_32bit_Stride                  = glGetUniformLocation(SHADER_shadow_32bit_Stride, "offset"); 
