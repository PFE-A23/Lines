#ifndef __WideLine_h_
#define __WideLine_h_

#include "drwDataArray.h"
#include "LinePrimitive.h"
#include "Box2d.h"

class drwGlslShader;
class drwDrawingContext;

class WideLine : public LinePrimitive
{

public:

	WideLine( double width );
    ~WideLine();
    
    virtual void StartPoint( double x, double y, double pressure );
    virtual void EndPoint( double x, double y, double pressure );
    virtual void AddPoint( double x, double y, double pressure );

	void SetPressureWidth( bool w ) { m_pressureWidth = w; }
	void SetPressureOpacity( bool o ) { m_pressureOpacity = o; }
	void SetFill( bool f ) { m_fill = f; }
	
    void InitShader( drwDrawingContext & context );

protected:
	
    virtual void InternDraw( drwDrawingContext & context );
    void AddLinePoint( double x, double y, double pressure );
	void AddFillPoint( double x, double y );

	// WideLine
    drwVec2Array m_vertices;
	drwVec3Array m_texCoord;
    drwVec3Array m_normals;
    drwIndexArray m_indices;

	// Fill
	drwVec2Array m_fillVertices;
	drwIndexArray m_fillIndices;

    // Line attributes
    double m_width;
	bool m_pressureWidth;
	bool m_pressureOpacity;
	bool m_fill;
    Box2d m_boundingBox;

    // cache previous point computation during editing
    Vec2       m_prevPoint;
	double	   m_prevPressure;
	bool m_doneAddingPoints;
};


#endif
