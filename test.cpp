#include "polyscope/point_cloud.h"
static int num_points_inc = 100;
// int main()
// {

//     // Initialize polyscope
//     polyscope::init();        

//     std::vector<glm::vec3> points;

//     // generate points
//     for (size_t i = 0; i < 3000; i++) {
//     points.push_back(
//         glm::vec3{polyscope::randomUnit() - .5, 
//                     polyscope::randomUnit() - .5, 
//                     polyscope::randomUnit() - .5});
//     }

//     // visualize!
//     polyscope::PointCloud* psCloud = polyscope::registerPointCloud("really great points", points);



//     // set some options
//     psCloud->setPointRadius(0.02);
//     psCloud->setPointRenderMode(polyscope::PointRenderMode::Quad);

//     // show
//     polyscope::show();
//     psCloud->updatePointPositions(points);
//     polyscope::show();

//     return 0;
// }

#include "polyscope/polyscope.h"
#include "polyscope/point_cloud.h"

// Parameters which we will set in the callback UI.
int nPts = 2000;
float anotherParam = 3.14;

void mySubroutine(int num_points) {

  // do something useful...

  // Register a structure
  std::vector<glm::vec3> points;
  for (int i = 0; i < num_points; i++) {
    points.push_back(
        glm::vec3{ i / 100.f,//polyscope::randomUnit(), 
                   i / 100.f,//polyscope::randomUnit(), 
                   i / 100.f//polyscope::randomUnit()
                  });
  }
  polyscope::registerPointCloud("my point cloud", points);
}

// Your callback functions
void myCallback() {

  // Since options::openImGuiWindowForUserCallback == true by default, 
  // we can immediately start using ImGui commands to build a UI

  ImGui::PushItemWidth(100); // Make ui elements 100 pixels wide,
                             // instead of full width. Must have 
                             // matching PopItemWidth() below.

  ImGui::InputInt("num points", &nPts);             // set a int variable
  ImGui::InputFloat("param value", &anotherParam);  // set a float variable

//   if (ImGui::Button("run subroutine")) {
//     // executes when button is pressed
    mySubroutine(num_points_inc++);
//   }
  ImGui::SameLine();
  if (ImGui::Button("hi")) {
    polyscope::warning("hi");
  }

  ImGui::PopItemWidth();
}

int main(int argc, char** argv) {

  /*
    ...your program setup...
  */ 

  // Initialize polyscope
  polyscope::init();


    polyscope::options::automaticallyComputeSceneExtents = false;
    polyscope::state::lengthScale = 1.;
    polyscope::state::boundingBox = 
        std::tuple<glm::vec3, glm::vec3>{ {-1., -1., -1.}, {1., 1., 1.} };

  // Specify the callback
  polyscope::state::userCallback = myCallback;

  // Give control to the polyscope gui
  polyscope::show();

  return EXIT_SUCCESS;
}