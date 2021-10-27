
      dimensionedScalar rhoInfValue
      (
          transportProperties.lookup("rhoInf")
      );

      dimensionedScalar invrhoInf("invrhoInf",(1.0/rhoInfValue));

      volScalarField rhoInf
      (
          IOobject
          (
              "rho",
              runTime.timeName(),
              mesh,
              IOobject::NO_READ,
              IOobject::NO_WRITE
          ),
          mesh,
          rhoInfValue
      );

      volScalarField mu
      (
          IOobject
          (
              "mu",
              runTime.timeName(),
              mesh,
              IOobject::NO_READ,
              IOobject::NO_WRITE
          ),
          laminarTransport.nu()*rhoInfValue
      );

// ----------------------------------------------------------------------------

      const word kinematicCloudName3
      (
          args.optionLookupOrDefault<word>("cloudName", "kinematicCloud3")
      );

      Info<< "Constructing kinematicCloud3 " << kinematicCloudName3 << endl;
      basicKinematicCollidingCloud kinematicCloud3
      (
          kinematicCloudName3,
          rhoInf,
          U,
          mu,
          g
      );

