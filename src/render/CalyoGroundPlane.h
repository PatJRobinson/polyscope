// #include <glad/glad.h>

// void draw_grid()
// {
    

//   std::vector<glm::vec3> vertices;
//   std::vector<glm::uvec4> indices;

// size_t slices = 10;

//   for(int j=0; j<=slices; ++j) {
//     for(int i=0; i<=slices; ++i) {
//       float x = (float)i/(float)slices;
//       float y = 0;
//       float z = (float)j/(float)slices;
//       vertices.push_back(glm::vec3(x, y, z));
//     }
//   }

//   for(int j=0; j<slices; ++j) {
//     for(int i=0; i<slices; ++i) {

//       int row1 =  j    * (slices+1);
//       int row2 = (j+1) * (slices+1);

//       indices.push_back(glm::uvec4(row1+i, row1+i+1, row1+i+1, row2+i+1));
//       indices.push_back(glm::uvec4(row2+i+1, row2+i, row2+i, row1+i));

//     }
//   }

//   GLuint vao;

//   glGenVertexArrays( 1, &vao );
//   glBindVertexArray( vao );

//   GLuint vbo;
//   glGenBuffers( 1, &vbo );
//   glBindBuffer( GL_ARRAY_BUFFER, vbo );
//   glBufferData( GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), glm::value_ptr(vertices[0]), GL_STATIC_DRAW );
//   glEnableVertexAttribArray( 0 );
//   glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, nullptr );

//   GLuint ibo;
//   glGenBuffers( 1, &ibo );
//   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ibo );
//   glBufferData( GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(glm::uvec4), glm::value_ptr(indices[0]), GL_STATIC_DRAW);

//   glBindVertexArray(0);
//   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//   glBindBuffer(GL_ARRAY_BUFFER, 0);

//   size_t length = (GLuint)indices.size()*4;

//     // render
//       glEnable(GL_DEPTH_TEST);

//   glBindVertexArray(vao);

//   glDrawElements(GL_LINES, length, GL_UNSIGNED_INT, NULL);

//   glBindVertexArray(0);

//   glDisable(GL_DEPTH_TEST);

// }