/*
This file is part of the Ristra portage project.
Please see the license file at the root of this repository, or at:
    https://github.com/laristra/portage/blob/master/LICENSE
*/
#include "intersect_r3d.h"
#include "gtest/gtest.h"
#include "portage/wonton/mesh/simple_mesh/simple_mesh_wrapper.h"

TEST(intersectR3D, simple1) {
  Portage::Simple_Mesh sm{0, 0, 0, 2, 2, 2, 1, 1, 1};
  Portage::Simple_Mesh tm{1, 1, 1, 2, 2, 2, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++){
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
    }

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 1, eps);
  ASSERT_NEAR(moments[1]/moments[0], 1.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1.5, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1.5, eps);
}

TEST(intersectR3D, simple2) {
  Portage::Simple_Mesh sm{0, 0, 0, 2, 2, 2, 1, 1, 1};
  Portage::Simple_Mesh tm{0, 0, 0, 2, 2, 2, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++){
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
  }

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 8, eps);
  ASSERT_NEAR(moments[1]/moments[0], 1, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1, eps);
}

TEST(intersectR3D, simple3) {
  Portage::Simple_Mesh sm{0, 0, 0, 3, 3, 3, 1, 1, 1};
  Portage::Simple_Mesh tm{1, 1, 1, 2, 2, 2, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++){
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
  }

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 1, eps);
  ASSERT_NEAR(moments[1]/moments[0], 1.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1.5, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1.5, eps);
}

TEST(intersectR3D, simple4) {
  Portage::Simple_Mesh sm{0, 0, 0, 2, 2, 2, 1, 1, 1};
  Portage::Simple_Mesh tm{1, 1, 1, 3, 3, 3, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++){
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
  }

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 1, eps);
  ASSERT_NEAR(moments[1]/moments[0], 1.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1.5, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1.5, eps);
}

TEST(intersectR3D, simple5) {
  Portage::Simple_Mesh sm{0, 0, 0, 10, 10, 10, 1, 1, 1};
  Portage::Simple_Mesh tm{-5, -5, -5, 5, 5, 5, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++){
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
  }

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 125, eps);
  ASSERT_NEAR(moments[1]/moments[0], 2.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], 2.5, eps);
  ASSERT_NEAR(moments[3]/moments[0], 2.5, eps);
}

TEST(intersectR3D, simple6) {
  Portage::Simple_Mesh sm{0, 0, 0, 10, 10, 10, 5, 5, 5};
  Portage::Simple_Mesh tm{0, 0, 0, 10, 10, 10, 2, 2, 2};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++)
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 8, eps);
  ASSERT_NEAR(moments[1]/moments[0], 1, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1, eps);

  srccells[0] = 1;
  srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  srcent = srcwts[0].entityID;
  moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++)
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 8, eps);
  ASSERT_NEAR(moments[1]/moments[0], 3, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1, eps);

  srccells[0] = 2;
  srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  srcent = srcwts[0].entityID;
  moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++)
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 4, eps);
  ASSERT_NEAR(moments[1]/moments[0], 4.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], 1, eps);
  ASSERT_NEAR(moments[3]/moments[0], 1, eps);
}

TEST(intersectR3D, simple7) {
  Portage::Simple_Mesh sm{-2, -2, -2, 0, 0, 0, 1, 1, 1};
  Portage::Simple_Mesh tm{-1, -1, -1, 0, 0, 0, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);
  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++){
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
  }

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 1, eps);
  ASSERT_NEAR(moments[1]/moments[0], -0.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], -0.5, eps);
  ASSERT_NEAR(moments[3]/moments[0], -0.5, eps);
}

TEST(intersectR3D, simple8) {
  Portage::Simple_Mesh sm{-4, -4, -4, 0, 0, 0, 1, 1, 1};
  Portage::Simple_Mesh tm{-3, -3, -3, 0, 0, 0, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s , t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++)
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 27, eps);
  ASSERT_NEAR(moments[1]/moments[0], -1.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], -1.5, eps);
  ASSERT_NEAR(moments[3]/moments[0], -1.5, eps);
}

TEST(intersectR3D, simple9) {
  Portage::Simple_Mesh sm{-4, -3, -2, 0, 1, 2, 1, 1, 1};
  Portage::Simple_Mesh tm{-3, -2, -1, 0, 1, 2, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s, t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(1, srcwts.size());
  int srcent = srcwts[0].entityID;
  std::vector<double> moments = srcwts[0].weights;
  for(int j=0;j<moments.size();j++)
    std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;

  ASSERT_TRUE(moments.size() == 4);

  ASSERT_NEAR(moments[0], 27, eps);
  ASSERT_NEAR(moments[1]/moments[0], -1.5, eps);
  ASSERT_NEAR(moments[2]/moments[0], -0.5, eps);
  ASSERT_NEAR(moments[3]/moments[0],  0.5, eps);
}

// in this test, the cubes don't intersect at all
TEST(intersectR3D, cube_no_intersect) {

  Portage::Simple_Mesh sm{0, 0, 0, 1, 1, 1, 1, 1, 1};
  Portage::Simple_Mesh tm{2, 0, 0, 3, 1, 1, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s, t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  ASSERT_EQ(0, srcwts.size());
}

// in this test, the cubes share a face but have zero intersection volume
TEST(intersectR3D, cube_0_1) {

  Portage::Simple_Mesh sm{0, 0, 0, 1, 1, 1, 1, 1, 1};
  Portage::Simple_Mesh tm{1, 0, 0, 2, 1, 1, 1, 1, 1};
  const Wonton::Simple_Mesh_Wrapper s(sm);
  const Wonton::Simple_Mesh_Wrapper t(tm);

  const double eps = 1e-12;
  const Portage::IntersectR3D<Portage::Entity_kind::CELL,
                              Wonton::Simple_Mesh_Wrapper,
                              Wonton::Simple_Mesh_Wrapper> isect{s, t};
  std::vector<int> srccells({0});
  const std::vector<Portage::Weights_t> srcwts = isect(0, srccells);

  // We can't be sure that this will or will not give an intersection.
  // Check for 0 moments if we do get an intersection
  if (srcwts.size()) {
    ASSERT_EQ(1, srcwts.size());
    int srcent = srcwts[0].entityID;
    std::vector<double> moments = srcwts[0].weights;
    for(int j=0;j<moments.size();j++)
      std::cout << "i, j, m " << srcent << ", " << j << ", " << moments[j] << std::endl;
    
    ASSERT_TRUE(moments.size() == 4);
    
    ASSERT_NEAR(moments[0], 0, eps);
    ASSERT_NEAR(moments[1], 0, eps);
    ASSERT_NEAR(moments[2], 0, eps);
    ASSERT_NEAR(moments[3], 0, eps);
  }
}
