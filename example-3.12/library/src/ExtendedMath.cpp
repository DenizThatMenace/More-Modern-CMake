#include <string>

// Requires Boost.Graph
#include "boost/graph/graphviz.hpp"


// Vertex properties
typedef boost::property < boost::vertex_name_t, std::string,
          boost::property < boost::vertex_color_t, float > > vertex_p;
// Edge properties
typedef boost::property < boost::edge_weight_t, double > edge_p;
// Graph properties
typedef boost::property < boost::graph_name_t, std::string > graph_p;
// adjacency_list-based type
typedef boost::adjacency_list < boost::vecS, boost::vecS, boost::directedS,
  vertex_p, edge_p, graph_p > graph_t;

// Construct an empty graph and prepare the dynamic_property_maps.
graph_t graph_obj(0);
auto dp = boost::dynamic_properties{};

boost::property_map<graph_t, boost::vertex_name_t>::type name =
  get(boost::vertex_name, graph_obj);
//dp.property("node_id",name);

boost::property_map<graph_t, boost::vertex_color_t>::type mass =
  get(boost::vertex_color, graph_obj);
//dp.property("mass",mass);

boost::property_map<graph_t, boost::edge_weight_t>::type weight =
  get(boost::edge_weight, graph_obj);
//dp.property("weight",weight);

// Use ref_property_map to turn a graph property into a property map
boost::ref_property_map<graph_t*,std::string>
  gname(boost::get_property(graph_obj,boost::graph_name));
//dp.property("name",gname);

// Sample graph as an std::istream;
std::istringstream
  gvgraph("digraph { graph [name=\"graphname\"]  a  c e [mass = 6.66] }");

bool status = boost::read_graphviz(gvgraph,graph_obj,dp,"node_id");
