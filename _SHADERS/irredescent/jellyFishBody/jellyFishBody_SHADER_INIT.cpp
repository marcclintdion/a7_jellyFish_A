    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      jellyFishBody_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_jellyFishBody =                                                                                                        

      "    #define highp                                                                                                                         \n"        

      "    uniform highp vec4   light_POSITION_01;                                                                                               \n"        
      "    uniform highp vec4   light_POSITION_02;                                                                                               \n"        
      "    uniform highp vec4   light_POSITION_03;                                                                                               \n"        
      "    uniform highp vec4   light_POSITION_04;                                                                                               \n"        
     
      
      //----------------------
      "    varying highp vec4   lightPosition_PASS;                                                                                              \n" 
      "    varying highp vec4   lightPosition_PASS_02;                                                                                              \n" 
      "    varying highp vec4   lightPosition_PASS_03;                                                                                              \n" 
      "    varying highp vec4   lightPosition_PASS_04;                                                                                              \n" 
      
      //--------------------------------------------           
      "    uniform       mat4   mvpMatrix;                                                                                                       \n"      
      "    uniform       mat4   mvMatrix;                                                                                                        \n"  
           //-----
      "    uniform       mat4   viewMatrix;                                                                                                      \n"                   
           //-----
      "    uniform       mat4   projectionShadow;                                                                                                \n"        
      "    uniform       mat4   modelViewShadow;                                                                                                 \n"        
           //-----   
      "    uniform       mat4   lightMatrix;                                                                                                     \n"     
      "    uniform       mat4   textureMatrix;                                                                                                   \n"  
           //-----
      "    attribute     vec4   position;                                                                                                        \n"      
      "    attribute     vec2   texture;                                                                                                         \n"       

      "    uniform      float   generic;                                                                                                         \n"       
      

      //--------------------------------------------      
      "    varying highp vec4   shadowTexcoord;                                                                                                  \n"
      "            const mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);              \n"
      //-------------------------------------------- 
      "    varying highp vec2  varTexcoord;                                                                                                      \n"
      
      "    varying highp float  dist;                                                                                                            \n"
      "            highp vec4   ecPos;                                                                                                           \n"
      "            highp vec3   aux;                                                                                                             \n"
      //=========================================================================================================================================
      "    void main()                                                                                                                           \n" 
      "    {                                                                                                                                     \n"
                   //---------------------------------------------------------------------------------------------------------
      "            ecPos                 =  mvpMatrix * position;                                                                                \n"
      "            aux                   =  vec3(light_POSITION_01 - ecPos);                                                                     \n"
      "            dist                  =  length(aux);                                                                                         \n"
                   //---------------------------------------------------------------------------------------------------------     
     
      "            shadowTexcoord        =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;                \n" 
      "            shadowTexcoord        =   shadowTexcoord / shadowTexcoord.w;                                                                  \n"      
                   //---------------------------------------------------------------------------------------------------------
      "            lightPosition_PASS    =  normalize(lightMatrix * light_POSITION_01);                                                          \n"        
      "            lightPosition_PASS_02 =  normalize(lightMatrix * light_POSITION_02);                                                          \n"        
      "            lightPosition_PASS_03 =  normalize(lightMatrix * light_POSITION_03);                                                          \n"        
      "            lightPosition_PASS_04 =  normalize(lightMatrix * light_POSITION_04);                                                          \n"        



      "            varTexcoord           =  texture;                                                                                             \n"          
      "            gl_Position           =  mvpMatrix * position;                                                                                 \n"           

      "    }\n";                                                                                                                             
      
      
      //---------------------------------------------------------------------                                                                   
      jellyFishBody_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(jellyFishBody_SHADER_VERTEX, 1, &vertexSource_jellyFishBody, NULL);                                                                        
      glCompileShader(jellyFishBody_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_jellyFishBody =                                                                                                            

      " #ifdef GL_ES                                                                                                                             \n"                       
      " #else                                                                                                                                    \n"                       
      " #define highp                                                                                                                            \n"                       
      " #endif                                                                                                                                   \n"   
    
      "    uniform sampler2D   Texture1;                                                                                                         \n"                       
      "    uniform sampler2D   NormalMap;                                                                                                        \n"                       
      //--------------------------------------------
      "    uniform sampler2D   ShadowTexture;                                                                                                    \n"     
      "    varying highp vec4  shadowTexcoord;                                                                                                   \n"  
      //--------------------------------------------         
      "    uniform highp float shininess;                                                                                                        \n"                       
      "    uniform highp float attenuation;                                                                                                      \n"                       
      //--------------------------------------------   
      "    varying highp vec4   lightPosition_PASS;                                                                                              \n" 
      "    varying highp vec4   lightPosition_PASS_02;                                                                                              \n" 
      "    varying highp vec4   lightPosition_PASS_03;                                                                                              \n" 
      "    varying highp vec4   lightPosition_PASS_04;                                                                                              \n" 
    
      
      //--------------------------------------------   

      "    varying highp vec2  varTexcoord;                                                                                                      \n"                       
      //--------------------------------------------   

      "            highp float NdotL1;                                                                                                           \n"                       
      "            highp float NdotL2;                                                                                                           \n"                       
      "            highp float NdotL3;                                                                                                           \n"                       
      "            highp float NdotL4;                                                                                                           \n"                       
     
      
      //--------------------------------   
      
      "            highp vec3  normal;                                                                                                           \n"                       
      "            highp vec3  NormalTex;                                                                                                        \n"                       

   
      "    varying highp float dist;                                                                                                             \n"

      "            highp float att;                                                                                                              \n"
      "            highp vec4  gloss_01;                                                                                                            \n"
      "            highp vec4  gloss_02;                                                                                                            \n"
      "            highp vec4  gloss_03;                                                                                                            \n"
      "            highp vec4  gloss_04;                                                                                                            \n"
    
    
    
      //=========================================================================================================================================
      "     void main()                                                                                                                          \n"                       
      "     {                                                                                                                                    \n"                       
   
      //-----------------------------------------------------------------------------------------------------------------------------    
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                                    \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                                     \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                                  \n" 
      //-----------------------------------------------------------------------------------------------------------------------------     
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                                             \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                                                   \n"                       
      "         normal                    =  normalize(NormalTex);                                                                               \n"                       
      "         NdotL1                    =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                                      \n"                       
      "         NdotL2                    =  max(dot(normal, lightPosition_PASS_02.xyz), 0.0);                                                      \n"                       
      "         NdotL3                    =  max(dot(normal, lightPosition_PASS_03.xyz), 0.0);                                                      \n"                       
      "         NdotL4                    =  max(dot(normal, lightPosition_PASS_04.xyz), 0.0);                                                      \n"                       


   
      "         gloss_01                  =  vec4(0.9, 1.0, 0.9, 1.0) * max(pow(NdotL1, shininess), 0.0) ;                \n"    
      "         gloss_02                  =  vec4(0.9, 1.0, 0.9, 1.0) * max(pow(NdotL2, shininess*0.9), 0.0) ;            \n"       
      "         gloss_04                  =  vec4(0.9, 1.0, 0.9, 1.0) * max(pow(NdotL4, shininess*0.4), 0.0) ;            \n"       
 
 
      "         gl_FragColor              =  (texture2D(Texture1, varTexcoord.st)* NdotL1 * NdotL1                                     \n"   
      "                                     + texture2D(Texture1, varTexcoord.st)* NdotL2 * NdotL2                             \n" 
      "                                     + texture2D(Texture1, varTexcoord.st)* NdotL3 * NdotL3                                     \n" 
      "                                     + texture2D(Texture1, varTexcoord.st)* NdotL4 * NdotL4)*0.4                                 \n" 
      
      
      "                                     +  (gloss_01 +  gloss_02+  gloss_04)* texture2D(Texture1, varTexcoord.st) ;                                                             \n"                       

   //    "        gl_FragColor.a              =  texture2D(Texture1, varTexcoord.st).b;                                     \n"   

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      jellyFishBody_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(jellyFishBody_SHADER_FRAGMENT, 1, &fragmentSource_jellyFishBody, NULL);                                                                          
      glCompileShader(jellyFishBody_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(jellyFishBody_SHADER, jellyFishBody_SHADER_VERTEX);                                                                                              
      glAttachShader(jellyFishBody_SHADER, jellyFishBody_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(jellyFishBody_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(jellyFishBody_SHADER,    1, "normal");       
      glBindAttribLocation(jellyFishBody_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(jellyFishBody_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(jellyFishBody_SHADER, jellyFishBody_SHADER_VERTEX);                                                                                              
      glDetachShader(jellyFishBody_SHADER, jellyFishBody_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(jellyFishBody_SHADER_VERTEX);                                                                                                            
      glDeleteShader(jellyFishBody_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_jellyFishBody                   = glGetUniformLocation(jellyFishBody_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_jellyFishBody                       = glGetUniformLocation(jellyFishBody_SHADER,      "mvMatrix");       
      //-------------------------------      
      UNIFORM_viewMatrix_jellyFishBody                      = glGetUniformLocation(jellyFishBody_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_jellyFishBody                     = glGetUniformLocation(jellyFishBody_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_jellyFishBody                 = glGetUniformLocation(jellyFishBody_SHADER,      "modelViewShadow");            
      //-------------------------------                                              
      UNIFORM_LIGHT_MATRIX_jellyFishBody                    = glGetUniformLocation(jellyFishBody_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_jellyFishBody                   = glGetUniformLocation(jellyFishBody_SHADER,      "textureMatrix"); 
      //-------------------------------  
      UNIFORM_SHADOW_PROJ_jellyFishBody                     = glGetUniformLocation(jellyFishBody_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_jellyFishBody                 = glGetUniformLocation(jellyFishBody_SHADER,      "modelViewShadow");            
      //-------------------------------  
      UNIFORM_LIGHT_POSITION_01_jellyFishBody               = glGetUniformLocation(jellyFishBody_SHADER,      "light_POSITION_01");                                      
      UNIFORM_LIGHT_POSITION_02_jellyFishBody               = glGetUniformLocation(jellyFishBody_SHADER,      "light_POSITION_02");       
      UNIFORM_LIGHT_POSITION_03_jellyFishBody               = glGetUniformLocation(jellyFishBody_SHADER,      "light_POSITION_03");      
      UNIFORM_LIGHT_POSITION_04_jellyFishBody               = glGetUniformLocation(jellyFishBody_SHADER,      "light_POSITION_04");      
      
      
      //-------------------------------        
      
      UNIFORM_SHININESS_jellyFishBody                       = glGetUniformLocation(jellyFishBody_SHADER,      "shininess");
      UNIFORM_GENERIC_jellyFishBody                         = glGetUniformLocation(jellyFishBody_SHADER,      "generic");      
                                                    
      UNIFORM_TEXTURE_SHADOW_jellyFishBody                  = glGetUniformLocation(jellyFishBody_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_DOT3_jellyFishBody                    = glGetUniformLocation(jellyFishBody_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_jellyFishBody                         = glGetUniformLocation(jellyFishBody_SHADER,      "Texture1");                                   

      


