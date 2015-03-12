namespace CGAL {

/*!
\ingroup PkgRidges_3Enums
The enum `Ridge_order` describes the order of differential quantities
used to distinguish elliptic and hyperbolic ridges. Third or fourth
order quantities may be used as explained in Section  \ref ridgemesh
of the User Manual.

\sa `Ridge_approximation`
*/
enum Ridge_order { Ridge_order_3 = 3, Ridge_order_4};

/*!
\ingroup PkgRidges_3Enums
The enum `Ridge_type` describes the types for the class `Ridge_line`.
\sa `Ridge_line`
*/
enum Ridge_type { 
  MAX_ELLIPTIC_RIDGE = 1, MAX_HYPERBOLIC_RIDGE,
  MAX_CREST_RIDGE, MIN_ELLIPTIC_RIDGE,
  MIN_HYPERBOLIC_RIDGE, MIN_CREST_RIDGE 
};


/*!
\ingroup PkgRidges_3

The function `compute_crest_ridges()` is a shortcut to the method of the same name 
of the class `Ridge_approximation`. 

The operator `<<` is overloaded for this class and returns the
line type, strength, sharpness and coordinates of the points of the
polyline.


*/
template < class TriangleMesh, 
           class VertexFTMap,
           class VertexVectorMap,
           class OutputIterator>
OutputIterator compute_crest_ridges(const TriangleMesh &P,
                                    VertexFTMap vertex2k1_pm,
                                    VertexFTMap vertex2k2_pm,
                                    VertexFTMap vertex2b0_pm,
                                    VertexFTMap vertex2b3_pm,
                                    VertexVectorMap vertex2d1_pm,
                                    VertexVectorMap vertex2d2_pm,
                                    VertexFTMap vertex2P1_pm,
                                    VertexFTMap vertex2P2_pm,
                                    OutputIterator it, 
                                    CGAL::Ridge_order order = CGAL::Ridge_order_3);

} /* namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgRidges_3

The function `compute_max_ridges()` is a shortcut to the method of the same name 
of the class `Ridge_approximation`. 

*/
template < class TriangleMesh, 
           class VertexFTMap,
           class VertexVectorMap,
           class OutputIterator>
OutputIterator compute_max_ridges(const TriangleMesh &P,
                                  VertexFTMap vertex2k1_pm,
                                  VertexFTMap vertex2k2_pm,
                                  VertexFTMap vertex2b0_pm,
                                  VertexFTMap vertex2b3_pm,
                                  VertexVectorMap vertex2d1_pm,
                                  VertexVectorMap vertex2d2_pm,
                                  VertexFTMap vertex2P1_pm, const
                                  VertexFTMap vertex2P2_pm,
                                  OutputIterator it, 
                                  CGAL::Ridge_order order = CGAL::Ridge_order_3);
  
} /* namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgRidges_3

The function `compute_min_ridges()` is a shortcut to the method of the same name 
of the class `Ridge_approximation`. 


*/
template < class TriangleMesh, 
class VertexFTMap,
class VertexVectorMap,
class OutputIterator>
OutputIterator compute_min_ridges(const TriangleMesh &P,
                                  VertexFTMap vertex2k1_pm, 
                                  VertexFTMap vertex2k2_pm,
                                  VertexFTMap vertex2b0_pm,
                                  VertexFTMap vertex2b3_pm,
                                  VertexVectorMap vertex2d1_pm,
                                  VertexVectorMap vertex2d2_pm,
                                  VertexFTMap vertex2P1_pm,
                                  VertexFTMap vertex2P2_pm,
                                  OutputIterator it, 
                                  CGAL::Ridge_order order = CGAL::Ridge_order_3);

} /* namespace CGAL */


namespace CGAL {

/*!
\ingroup PkgRidges_3

The class `Ridge_approximation` computes the approximation of 
ridges of a triangular polyhedral surface. 

\tparam TriangleMesh is the surface type. 
\tparam VertexFTMap property map with...
\tparam VertexVectorMap provide the differential properties of 
the surface associated to its vertices. 

Requirements (checked at compile time): 
- the types `TriangleMesh::Traits::FT` and 
 `boost::property_traits<VertexFTMap>::value_type` must coincide; 
- the types `TriangleMesh::Traits::Vector_3` and 
  `boost::property_traits<VertexVectorMap>::value_type` must coincide; 
- the types `boost::graph_traits<TriangleMesh>::vertex_descriptor`, 
  `boost::property_traits<VertexFTMap>::key_type` and 
  `boost::property_traits<VertexVectorMap>::key_type` must coincide; 

\sa `Ridge_line` 

*/
template< typename TriangleMesh, typename VertexFTMap, typename VertexVectorMap >
class Ridge_approximation {
public:

/// \name Types 
/// @{

/*!
Order of differential 
quantities used to distinguish elliptic and hyperbolic ridges. Third 
(`Tag_3`) or fourth (`Tag_4`) order quantities may be used as 
explained in Section \ref ridgemesh of the User Manual. 
*/ 
enum Tag_order {Tag_3, Tag_4}; 

/// @} 

/// \name Creation 
/// @{

/*!
The two last property maps may 
not be used if computations are performed with 
the parameter `Tag_3`, in which case these 
property maps shall be initialized with their 
default constructors. 

\param vertex2k1_pm
\param vertex2k2_pm
\param vertex2b0_pm
\param vertex2b3_pm
\param vertex2d1_pm
\param vertex2d2_pm
\param vertex2P1_pm
\param vertex2P2_pm
*/ 
Ridge_approximation(const TriangleMesh &P, 
                    VertexFTMap vertex2k1_pm,
                    VertexFTMap vertex2k2_pm,
                    VertexFTMap vertex2b0_pm,
                    VertexFTMap vertex2b3_pm,
                    VertexVectorMap vertex2d1_pm,
                    VertexVectorMap vertex2d2_pm,
                    VertexFTMap vertex2P1_pm,
                    VertexFTMap vertex2P2_pm); 

/*!
Outputs ridges of types `MAX_ELLIPTIC_RIDGE` and `MAX_HYPERBOLIC_RIDGE`. 
\tparam OutputIterator an output iterator wìth value type `Ridge_line*`. 
*/ 
template <class OutputIterator> OutputIterator compute_max_ridges(OutputIterator it, Tag_order ord = Tag_3); 

/*!
Outputs ridges of types `MIN_ELLIPTIC_RIDGE` and `MIN_HYPERBOLIC_RIDGE`. 
\tparam OutputIterator an output iterator with 
value type `Ridge_line*`. 
*/ 
template <class OutputIterator> OutputIterator compute_min_ridges(OutputIterator it, Tag_order ord = Tag_3); 

/*!
Outputs ridges of types `MAX_CREST_RIDGE` and `MIN_CREST_RIDGE`. 
\tparam OutputIterator is an output iterator with 
value type `Ridge_line*`. 
*/ 
template <class OutputIterator> OutputIterator compute_crest_ridges(OutputIterator it, Tag_order ord = Tag_3); 

/// @}

}; /* end Ridge_approximation */
} /* end namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgRidges_3

The class `Ridge_line` stores the description of a ridge line. The list 
of halfedges defines a connected sequence of edges (but not as 
oriented halfedges). The scalar \f$ b\f$ paired with a halfedge \f$ pq\f$ is the 
barycentric coordinate of the crossing point \f$ r\f$ with the ridge: 
\f$ r = b\times p + (1-b)\times q\f$. 

\sa `Ridge_approximation`

*/
template< typename TriangleMesh >
class Ridge_line {
public:

/// \name Types 
/// @{

/*!

*/ 
typedef typename TriangleMesh::Traits::FT FT; 

/*!

*/ 
  typedef typename boot::graph_traits<TriangleMesh>::halfedge_descriptor halfedge_descriptor; 

/*!
A halfedge crossed by a ridge is paired with the barycentric 
coordinate of the crossing point. 
*/ 
typedef std::pair< halfedge_descriptor, FT> Ridge_halfhedge; 

/// @} 

/// \name Creation 
/// @{

/*!
default constructor. 
*/ 
Ridge_line(); 

/// @} 

/// \name Access Functions 
/// @{

/*!

*/ 
Ridge_type line_type() const; 

/*!

*/ 
FT strength() const; 

/*!

*/ 
FT sharpness() const; 

/*!

*/ 
const std::list<Ridge_halfhedge>* line() const; 

/*!
Writes the line type, strength, sharpness and coordinates of the
points of the polyline to `os`.
*/
template< typename TriangleMesh >
std::ostream& operator<<(std::ostream& os, const Ridge_line<TriangleMesh>&);

/// @}

}; /* end Ridge_line */
} /* end namespace CGAL */

