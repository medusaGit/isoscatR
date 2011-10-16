#ifndef _RSCAT_STRUCTS_H
#define _RSCAT_STRUCTS_H

struct GlobalParams {
    
    int chain_num;
    
    int nRegions;
    int nLoci;
    int nInd;
    
    Rcpp::IntegerVector         nAlleles;
    
    arma::imat                  genotypes;
    Rcpp::IntegerVector         cvIndivs;
    arma::imat                  cvGenotypes;
    
    Rcpp::IntegerVector         indRegion;
    
    arma::mat                   predDist;
    
    std::vector<arma::mat>      count;          // NA  RxA[l]
    std::vector<arma::colvec>   sumCount;       // NA  Rx1
    std::vector<arma::mat>      allele_freq;    // NA  RxA[l]
    
    std::vector<double>         mu;             // NA
    std::vector<arma::rowvec>   eta;            // NA  1xA[l]
    std::vector<double>         beta;           // 1
    std::vector<double>         xi;             // 1
    
    std::vector<double>         alpha;          // 4
    
    std::vector<arma::mat>      X;              // NA  RxA[l]
    std::vector<arma::mat>      theta;          // NA  RxA[l]
    
    double                      anisoRatio;
    double                      anisoAngle;
    
    arma::mat                   anisoRatioMat;
    arma::mat                   anisoAngleMat;
    
    
    arma::mat                   dist;           // RxR
    arma::mat                   L;              // RxR
    
    std::vector<arma::colvec>   logLik;         // NA  Rx1

    arma::mat                   locs;           // Rx2
    arma::mat                   locsTrans;      // Rx2

    
    arma::mat                   boundary;
    
    std::vector<arma::colvec>   x_sd;        // NA   Rx1
    arma::rowvec                mu_sd;       
    arma::rowvec                eta_sd;      
    arma::rowvec                xi_sd;
    arma::rowvec                beta_sd;
    arma::rowvec                alpha_sd;
    double                      angle_sd;
    double                      ratio_sd;
    
    std::vector<arma::ucolvec>   Xattempt;        // NA   Rx1
    std::vector<arma::ucolvec>   Xaccept;         // NA   Rx1
    
    arma::urowvec                muAttempt;       // NA   
    arma::urowvec                muAccept;        // NA 
    
    arma::urowvec                etaAttempt;       
    arma::urowvec                etaAccept;       
    
    arma::urowvec                xiAttempt;
    arma::urowvec                xiAccept;
    
    arma::urowvec                betaAttempt;
    arma::urowvec                betaAccept;
    
    arma::urowvec                alphaAttempt;
    arma::urowvec                alphaAccept;
    
    unsigned int                 angleAttempt;
    unsigned int                 angleAccept;
    
    unsigned int                 ratioAttempt;
    unsigned int                 ratioAccept;

    std::vector<std::vector<boost::iostreams::filtering_ostream*> > alfileGzStreams;
    std::vector<std::vector<std::ofstream*> > alfileStreams;
    
    std::vector<boost::iostreams::filtering_ostream*> cvfileGzStreams;
    std::vector<std::ofstream*> cvfileStreams;
};

struct GlobalOptions {
    bool VERBOSE;
    std::string TMPDIR;
    std::string FILESUFFIX;
    
    bool ADAPT;
    int TUNEINTERVAL;
    
    bool USEMATERN;
    
    bool RETURNFIT;
    
    bool LOCATE;
    double MAXCELL;
    
    bool CROSSVALIDATE;
    
    double PSEUDOCOUNT;
    
    Rcpp::LogicalVector FIXALPHA;
    Rcpp::NumericVector ALPHA;
    Rcpp::NumericVector ALPHAMIN;
    Rcpp::NumericVector ALPHAMAX;
    
    Rcpp::NumericVector ALPHASD;
    
    bool FIXANGLE;
    double ANGLE;
    double ANGLESD;
    
    bool FIXRATIO;
    double RATIO;
    double RATIOSD;
    
    
    Rcpp::NumericVector XIRANGE;
    bool FIXXI;
    Rcpp::NumericVector XI;
    double XISD;
    double SIGMAXI;
    
    bool FIXMU;
    Rcpp::NumericVector MU;
    double MUSD;
    
    bool FIXETA;
    Rcpp::NumericVector ETA;
    double ETASD;
    
    Rcpp::NumericVector BETARANGE;
    bool FIXBETA;
    Rcpp::NumericVector BETA;
    double BETASD;
    double SIGMABETA;

    double XSD;
    
    double LOCALSD;
    double GLOBALSD;
    
    double NULLPROB;
    double DELTA;
};

#endif